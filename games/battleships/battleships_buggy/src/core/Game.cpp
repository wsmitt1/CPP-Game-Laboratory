#include "core/Game.h"

namespace bs {

    Game::Game(int width, int height)
        : m_width(width),
        m_height(height),
        m_players{ Player{"Player 1", width, height}, Player{"Player 2", width, height} }
    {
    }

    void Game::StartSetup()
    {
        m_state = GameState::Setup;
        m_current = 0;
        m_winner = -1;
        m_setupPlacedCount[0] = 0;
        m_setupPlacedCount[1] = 0;
    }

    PlaceResult Game::PlaceShipForCurrent(const Ship& ship)
    {
        if (m_state != GameState::Setup) return PlaceResult::Invalid;

        PlaceResult r = CurrentPlayerMut().own.PlaceShip(ship);
        if (r == PlaceResult::Ok)
            m_setupPlacedCount[m_current] += 1;

        return r;
    }

    void Game::NextPlayerDuringSetup()
    {
        // Hot-seat switch
        m_current = 1 - m_current;
    }

    void Game::FinishSetupIfReady()
    {
        // Intended by spec: only proceed when BOTH players placed ALL ships.
        // BUG: proceeds when *current player* finished, ignoring the other.
        int otherPlayer{ -1 };
        if (m_current == 0) { otherPlayer = 1; }
        else { otherPlayer = 0; }
        int shipLengthsSize = m_shipLengths.size();
        if (m_setupPlacedCount[m_current] >= static_cast<int>(shipLengthsSize) && m_setupPlacedCount[otherPlayer] >= static_cast<int>(shipLengthsSize)) // Attempt to fix the bug
        {
            m_state = GameState::Playing;
            m_current = 0; // Player 1 starts
        }
    }

    ShotResult Game::ShootAtOpponent(Coord c)
    {
        if (m_state != GameState::Playing) return ShotResult::Invalid;

        ShotResult r = OtherPlayerMut().own.Shoot(c);

        // BUG: tracking board update is wrong: we mark Hit cells as Ship instead of Hit.
        if (r == ShotResult::Miss)
            CurrentPlayerMut().tracking.SetCell(c, Cell::Miss);
        else if (r == ShotResult::Hit || r == ShotResult::Sunk)
            CurrentPlayerMut().tracking.SetCell(c, Cell::Hit); // BUG: should be Hit

        // BUG: win check uses current player's own board instead of opponent's board
        if (OtherPlayerMut().own.AllShipsSunk())
        {
            m_state = GameState::GameOver;
            m_winner = m_current; // BUG: declares shooter winner based on wrong check
            return r;
        }
        if (!(r == ShotResult::AlreadyTried)) {
            AdvanceTurn();
        }
        return r;
    }

    void Game::AdvanceTurn()
    {
        m_current = 1 - m_current;
    }

} // namespace bs