#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "general_utils.h"
#include "lab8_list.h"

int compare_firms(const void *a, const void *b)
{
  return strcmp(((BuildingFirm *)a)->name, (const char *)b);
}

void task1()
{
  Node *firms = NULL; // firms list

  char firm1[] = "Avantazh";
  char firm2[] = "Kharkiv Bud Development";
  char firm3[] = "StroyCity";
  char firm4[] = "MegaBuild";
  char firm5[] = "UrbanBuilders";

  insert_head_linked_list(&firms, create_building_firm(firm1));
  insert_head_linked_list(&firms, create_building_firm(firm2));
  insert_head_linked_list(&firms, create_building_firm(firm3));
  insert_head_linked_list(&firms, create_building_firm(firm4));
  insert_head_linked_list(&firms, create_building_firm(firm5));

  BuildingFirm *builderA = (BuildingFirm *)firms->data;
  insert_head_linked_list(&builderA->sublist, strdup("Block of flats"));
  insert_head_linked_list(&builderA->sublist, strdup("Office Building"));
  insert_head_linked_list(&builderA->sublist, strdup("Skyscraper 'Bluetech'"));
  insert_head_linked_list(&builderA->sublist, strdup("Apartment Complex"));

  BuildingFirm *builderB = (BuildingFirm *)firms->next->data;
  insert_head_linked_list(&builderB->sublist, strdup("Shopping Mall"));
  insert_head_linked_list(&builderB->sublist, strdup("Business Center"));
  insert_head_linked_list(&builderB->sublist, strdup("Residential Complex 'SunCity'"));

  BuildingFirm *builderC = (BuildingFirm *)firms->next->next->data;
  insert_head_linked_list(&builderC->sublist, strdup("Cultural Center"));
  insert_head_linked_list(&builderC->sublist, strdup("Sports Arena"));
  insert_head_linked_list(&builderC->sublist, strdup("Concert Hall"));

  BuildingFirm *builderD = (BuildingFirm *)firms->next->next->next->data;
  insert_head_linked_list(&builderD->sublist, strdup("Luxury Apartments"));
  insert_head_linked_list(&builderD->sublist, strdup("High-Tech Skyscraper"));
  insert_head_linked_list(&builderD->sublist, strdup("Eco-Friendly Office"));

  BuildingFirm *builderE = (BuildingFirm *)firms->next->next->next->next->data;
  insert_head_linked_list(&builderE->sublist, strdup("Urban Park"));
  insert_head_linked_list(&builderE->sublist, strdup("Family Housing Complex"));
  insert_head_linked_list(&builderE->sublist, strdup("Community Center"));

  highlightText("ALL AVAIBLE FIRMS\n", "blue");

  print_linked_list(firms, print_building_firm);

  highlightText("DELETING FIRMS: Avantazh, StroyCity, UrbanBuilders\n", "blue");
  delete_node_linked_list(&firms, firm1, compare_firms, destroy_building_firm);
  delete_node_linked_list(&firms, firm3, compare_firms, destroy_building_firm);
  delete_node_linked_list(&firms, firm5, compare_firms, destroy_building_firm);

  highlightText("ALL AVAIBLE FIRMS\n", "blue");
  print_linked_list(firms, print_building_firm);

  destroy_linked_list(&firms, destroy_building_firm);
}