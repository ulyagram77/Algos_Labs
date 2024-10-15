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

void task1() {
  struct power_source batterySource = {
      BATTERY_TYPE, {.battery = {500, 3000, 80, 8, CHARGED}}, 150.0};

  struct power_source chargerSource = {
      CHARGER_TYPE, {.charger = {220, 500, 120, 3000, 4, REPEATED_USE}}, 75.0};

  struct power_source items[5] = {
      {BATTERY_TYPE, {.battery = {600, 4000, 90, 10, CHARGED}}, 175.0},
      {CHARGER_TYPE, {.charger = {250, 600, 100, 2000, 3, REPEATED_USE}}, 60.0},
      {BATTERY_TYPE, {.battery = {450, 2500, 60, 6, CHARGED}}, 120.0},
      {CHARGER_TYPE, {.charger = {180, 400, 80, 1500, 2, REPEATED_USE}}, 45.0},
      {BATTERY_TYPE, {.battery = {550, 3500, 75, 7, CHARGED}}, 145.0}};

  printf("%d\n", sizeof(items));
};
