cell checkCellStates(cell c) {
  if (c.toChangeState == 1) {
    c.currentState = c.nextState;

    if (c.nextState == 2)
      currentRecovered++;
    else if (c.nextState == 3)
      currentDead++;

    c.toChangeState = 0;
  }

  return c;
}

/*
 * Update cell values after full iteration
 * Avoids bad checking of neighbors
 */
void updateCellStates() {
  int x, y;
  for (x = 0; x < cellCount; x++)
    for (y = 0; y < cellCount; y++)
      cells[x][y] = checkCellStates(cells[x][y]);
}
