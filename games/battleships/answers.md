# Battleships Buggy Lab — Answers

## Team
- Team name: 
- Partner A: William Smitt
- Partner B: Elliot Cigehn

---

## 1) Requirement → Code Map (spec verification)

Fill this table by reading `games/battleships/specification.md` and mapping requirements to code.

Requirement (from specification.md) | Pass/Fail/Unsure | Code location (file + class/function) | Notes (what it does)
---|---|---|---
Ship placement must be validated | Fail | `battleships_buggy/src/core/Board.cpp` → `Board::CanPlaceShip` | checks if ship is out of bounds or overlaps
Player placement turns switching | Fail | `battleships_buggy/src/core/Game.cpp` → `Game::NextPlayerDuringSetup` | updates `m_current`
Playing phase starts when both players placed all ships | Fail | `battleships_buggy/src/core/Game.cpp` → `Game::FinishSetupIfReady` | checks if all ships are placed
Game reports shot result and updates board | Pass | `battleships_buggy/src/core/Game.cpp` → `Game::ShootAtOpponent` | Shoots at coordinate and reports result
Turns alternate until a win condition is reached | Pass | `battleships_buggy/src/core/Game.cpp` → `Game::AdvanceTurn` | updates `m_current`
Robust input handling | Fail | `battleships_buggy/src/core/Coord.cpp` → `Coord::ParseCoordLoose` | validates user input
Informative ship placement error | Fail | `battleships_buggy/src/core/main.cpp` | checks placement result and displays error
Win condition is reached when all opposing ships are sunk | Fail | `battleships_buggy/src/core/Board.cpp` → `Board::AllShipsSunk` | checks IsSunk() on every ship and reports results

Add rows for all major requirements you verify.

---

## 2) Spec verification summary

Write Pass/Fail/Unsure for each area and explain *how you verified it* (test steps or observation).

- Setup phase: Fail
  We tried to play the game from start to finish and verified that the setup phase was broken, because Player 2 never got to place any ships.
- Placement rules: Fail
  We tried to type in random numbers and characters to see if that would affect placement, and verified that ships would sometimes be placed even with invalid coordinates.
- Input commands: Pass
  We played the game and did not encounter any issues regarding input commands.
- Shot resolution: Fail
  We saw that shooting a spot you already tried reports a miss and overwrites a possible hit in that area.
- Tracking board: Fail
  We played the game and tried to reach a win condition and noticed that some parts of ships reported misses.
- Win condition: Fail
  We played the game and noticed that the wrong player was winning.

---

## 3) Bugs found (at least 6 total)

You must list at least:
- 3 functional bugs (incorrect behavior vs spec)
- 3 robustness issues (bad input handling, silent failures, crashes, etc.)

### Bug 1
- Symptom:
- Steps to reproduce (exact inputs):
- Expected (spec):
- Actual:
- Suspected root cause (file/function):
- Fix approach:

### Bug 2
- Symptom:
- Steps to reproduce (exact inputs):
- Expected (spec):
- Actual:
- Suspected root cause (file/function):
- Fix approach:

### Bug 3
- Symptom:
- Steps to reproduce (exact inputs):
- Expected (spec):
- Actual:
- Suspected root cause (file/function):
- Fix approach:

### Bug 4
- Symptom:
- Steps to reproduce (exact inputs):
- Expected (spec):
- Actual:
- Suspected root cause (file/function):
- Fix approach:

### Bug 5
- Symptom:
- Steps to reproduce (exact inputs):
- Expected (spec):
- Actual:
- Suspected root cause (file/function):
- Fix approach:

### Bug 6
- Symptom:
- Steps to reproduce (exact inputs):
- Expected (spec):
- Actual:
- Suspected root cause (file/function):
- Fix approach:

(Add more if you find more.)

---

## 4) Code smells found (at least 5)

A “smell” is not necessarily a bug, but a design/implementation choice that increases risk or cost.

### Smell 1
- What (where in code):
- Why risky:
- Better approach (short plan):

### Smell 2
- What (where in code):
- Why risky:
- Better approach (short plan):

### Smell 3
- What (where in code):
- Why risky:
- Better approach (short plan):

### Smell 4
- What (where in code):
- Why risky:
- Better approach (short plan):

### Smell 5
- What (where in code):
- Why risky:
- Better approach (short plan):

---

## 5) Good patterns found (at least 4)

Find at least 4 things the code does reasonably well.

### Good thing 1
- Where:
- Why good:
- How to reuse:

### Good thing 2
- Where:
- Why good:
- How to reuse:

### Good thing 3
- Where:
- Why good:
- How to reuse:

### Good thing 4
- Where:
- Why good:
- How to reuse:

---

## 6) Team bug-fix PR (pair programming)

- Branch name:
- PR link:
- Bugs fixed (list):
- Tests added/updated:
- How you verified the fixes:
- What you learned:

---

## 7) Team feature PR (pair programming)

- Feature implemented (from spec’s “Explicit Missing Features”):
- Branch name:
- PR link:

Mini-spec (write BEFORE coding):
- Behavior:
- Edge cases:
- How to verify (test or manual steps):

Verification performed:
- Tests/manual steps used:
- Result:

---

## 8) Individual feature PRs

### Partner A
- Feature:
- Branch:
- PR link:

Mini-spec:
- Behavior:
- Edge cases:
- How to verify:

Verification performed:
- Tests/manual steps used:
- Result:

### Partner B
- Feature:
- Branch:
- PR link:

Mini-spec:
- Behavior:
- Edge cases:
- How to verify:

Verification performed:
- Tests/manual steps used:
- Result:

---

## 9) Manual test script (if needed)

If you could not write tests for some behavior, write a reproducible manual test script.

Example format:
1) Start game
2) Place ships for both players with valid placements
3) Player 1 shoots A1 → expect: Miss/Hit/Sunk
4) Player 1 shoots A1 again → expect: AlreadyTried and turn should NOT change
