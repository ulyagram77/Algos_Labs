#include "general_utils.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum { CHARGED, REPEATED_USE } Status;

typedef enum { BATTERY_TYPE, CHARGER_TYPE } PowerSourceType;

typedef struct {
  unsigned int voltage : 10; // Напряжение батареи в десятых долях вольта (0 -
                             // 1023, что позволяет хранить до 102.3 В)
  unsigned int capacity : 12; // Ёмкость батареи в ампер-часах (0 - 4095,
                              // например, для хранения до 409.5 Ah)
  unsigned int chargeLevel : 7; // Уровень заряда в процентах (0-100)
  unsigned int cellCount : 4; // Количество ячеек в батарее (до 15 ячеек)
  Status status;
} Battery;

typedef struct {
  unsigned int voltage : 10; // Напряжение зарядного устройства в десятых долях
                             // вольта (0-1023, до 102.3 В)
  unsigned int current : 10; // Ток зарядного устройства в десятых долях ампера
                             // (0-1023, до 102.3 А)
  unsigned int
      chargeTime : 12; // Время зарядки в минутах (0-4095, до 4095 минут)
  unsigned int maxCapacity : 12; // Максимальная ёмкость аккумулятора, с которым
                                 // можно работать (0-4095 Ah)
  unsigned int portCount : 4; // Количество доступных зарядных портов (0-15)
  Status status;
} Charger;

typedef union {
  Battery battery;
  Charger charger;
} PowerUnion;

struct power_source {
  PowerSourceType
      sourceType; // Тип источника питания (батарея или зарядное устройство)
  PowerUnion source; // Вариативная часть (батарея или зарядное устройство)
  float cost;        // Стоимость
};

void print_internal_int(int val) {
  for (size_t i = 0; i < sizeof(int); i++) {
    printBinary((unsigned char)(val >> (i * 8)));
  }
  printf("\n");
}

void print_internal_float(float val) {
  unsigned char *floatBytes = (unsigned char *)&val;
  for (int i = 0; i < sizeof(float); i++) {
    printBinary(floatBytes[i]);
  }
  printf("\n");
}

void print_binary_struct(void *ptr, size_t size) {
  unsigned char *byte = (unsigned char *)ptr;
  for (size_t i = 0; i < size; ++i) {
    // printf("%d) ", i + 1);
    printBinary(byte[i]);
  }
  printf("\n");
}

void print_binary_array_of_struct(const struct power_source *arr, int size) {
  for (int i = 0; i < size; ++i) {
    printf("\033[32m%d)\033[0m ", i + 1);
    print_binary_struct(&arr[i], sizeof(arr[i]));
  }
  printf("\n");
}

void print_binary_struct_fields(const struct power_source *ps) {
  printf("\033[32msourceType field: \033[0m");
  print_internal_int(ps->sourceType);

  if (ps->sourceType == BATTERY_TYPE) {
    printf("\033[32msource field (Battery type): \033[0m");
    print_binary_struct(&ps->source.battery, sizeof(ps->source.battery));
  } else if (ps->sourceType == CHARGER_TYPE) {
    printf("\033[32msource field (Charger type): \033[0m");
    print_binary_struct(&ps->source.charger, sizeof(ps->source.charger));
  }

  printf("\033[32mcost field: \033[0m");
  print_internal_float(ps->cost);
}

void print_struct_fields(const struct power_source *ps) {
  printf("sourceType: \033[32m%d\033[0m\n", ps->sourceType);

  if (ps->sourceType == BATTERY_TYPE) {
    printf("Battery: { \n voltage: \033[32m%d\033[0m,\n capacity: "
           "\033[32m%d\033[0m,\n "
           "chargeLevel: \033[32m%d\033[0m,\n cellCount: "
           "\033[32m%d\033[0m,\n status: \033[32m%d\033[0m\n }\n",
           ps->source.battery.voltage, ps->source.battery.capacity,
           ps->source.battery.chargeLevel, ps->source.battery.cellCount,
           ps->source.battery.status);
  } else if (ps->sourceType == CHARGER_TYPE) {
    printf("Charger: { \n voltage: \033[32m%d\033[0m,\n current: "
           "\033[32m%d\033[0m,\n chargeTime: \033[32m%d\033[0m,\n "
           "maxCapacity: \033[32m%d\033[0m,\n portCount: "
           "\033[32m%d\033[0m,\n status: \033[32m%d\033[0m\n }\n",
           ps->source.charger.voltage, ps->source.charger.current,
           ps->source.charger.chargeTime, ps->source.charger.maxCapacity,
           ps->source.charger.portCount, ps->source.charger.status);
  }

  printf("cost: \033[32m%.2f\033[0m\n", ps->cost);
}

void task1() {
  struct power_source batterySource = {
      BATTERY_TYPE, {.battery = {500, 3000, 80, 8, CHARGED}}, 150.0};

  struct power_source items[5] = {
      {BATTERY_TYPE, {.battery = {600, 4000, 90, 10, CHARGED}}, 175.0},
      {CHARGER_TYPE, {.charger = {250, 600, 100, 2000, 3, REPEATED_USE}}, 60.0},
      {BATTERY_TYPE, {.battery = {450, 2500, 60, 6, CHARGED}}, 120.0},
      {CHARGER_TYPE, {.charger = {180, 400, 80, 1500, 2, REPEATED_USE}}, 45.0},
      {BATTERY_TYPE, {.battery = {550, 3500, 75, 7, CHARGED}}, 145.0}};

  highlightText("Field values of struct: ", "blue");
  print_struct_fields(&batterySource);
  printf("\n");

  highlightText("Machine representation of struct field values: ", "blue");
  print_binary_struct_fields(&batterySource);
  printf("\n");

  highlightText("Machine representation of struct: ", "blue");
  print_binary_struct(&batterySource, sizeof(batterySource));
  printf("\n");

  highlightText("Machine representation of array with structs: ", "blue");
  print_binary_array_of_struct(&items, 5);
};
