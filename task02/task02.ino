#include <TaskManagerIO.h>

bool pin5State = false;
bool pin6State = false;
bool pin9State = false;
bool pin10State = false;
bool pin11State = false;


void checkState5() {
    digitalWrite(5, pin5State);
    pin5State = !pin5State;           
}

void checkState6() {
    digitalWrite(6, pin6State);
    pin6State = !pin6State;           
}

void checkState9() {
    digitalWrite(9, pin9State);
    pin9State = !pin9State;           
}

void checkState10() {
    digitalWrite(10, pin10State);
    pin10State = !pin10State;           
}

void checkState11() {
    digitalWrite(11, pin11State);
    pin11State = !pin11State;           
}

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  taskManager.scheduleFixedRate(350000, checkState5, TIME_MICROS);
  taskManager.scheduleFixedRate(150000, checkState6, TIME_MICROS);
  taskManager.scheduleFixedRate(3000, checkState9, TIME_MICROS);
  taskManager.scheduleFixedRate(33, checkState10, TIME_MICROS);
  taskManager.scheduleFixedRate(20, checkState11, TIME_MICROS);

}

void loop() {
  taskManager.runLoop();
}
