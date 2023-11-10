#include <stdio.h>

#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "ITSC.h"

int main(int argc, char *argv[])
{
  db db_r, db_c, *db1;
  int nf, nc, id_c;
  char *path_root = "./RAW_Signals/";
  char *path_root2 = "./Cropped_Signals_SF/";
  if(argc==2) {
    load_data_raw(&db_r, argv[1]);
    load_data_cropped(&db_c, argv[1]);
  }
  else {
    load_data_raw(&db_r, path_root);
    load_data_cropped(&db_c, path_root2);
  }
  db1=&db_r;
  show_db(*db1);
  summarized(*db1);
  id_c = search_class(*db1, "SC_A4_B0_C0");
  if(id_c==-1)
    printf("Class not found.\n");
  else
    printf("%s (%d)\n", db1->cls_h[id_c].name, db1->cls_h[id_c].n);
  id_c = search_class(*db1, "SC_A5_B0_C0");
  if(id_c==-1)
    printf("Class not found.\n");
  else
    printf("%s (%d)\n", db1->cls_h[id_c].name, db1->cls_h[id_c].n);
  id_c = find_class(*db1, 0, 20, 0);
  if(id_c==-1)
    printf("Class not found.\n");
  else
    printf("%s (%d)\n", db1->cls_h[id_c].name, db1->cls_h[id_c].n);
  id_c = find_class(*db1, 0, 20, 30);
  if(id_c==-1)
    printf("Class not found.\n");
  else
    printf("%s (%d)\n", db1->cls_h[id_c].name, db1->cls_h[id_c].n);
  return 0;
}