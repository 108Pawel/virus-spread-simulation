// Sean Moloney, Pawel Poreba, Piotr Poreba, Liam Rooney

#include "main.h"
#include "initFunc.c"
#include "drawFunc.c"

/*
 * Begin the program
 */
static void activate (GtkApplication* app, gpointer user_data) {
  /*
   * See initFunc.h/c
   */
  createCells();

  totalCells = cellCount * cellCount;

  printf("Running...\n");

  /*
   * Has Window
   */
  if (hasWindow == 1)
    createWindow(app, user_data);
  else
    runIteration();
}

int main (int argc, char **argv) {
  GtkApplication *app = gtk_application_new ("org.pc.ebola", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

  int status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
