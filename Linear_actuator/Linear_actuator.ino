#import <Arduino.h>
#include <Arduino.h>
#include "pins.h" // Ensure pin.h is correctly configured to define PIN_TYPE and possibly the pins used.
#include "actuator.h" 

// Global state instance
extern GlobalState global_state; // Use the existing GlobalState from the main scripts.

// Define pin numbers (make sure these match your actual wiring).
#define MOTOR_PUSH_PIN 6
#define MOTOR_PULL_PIN 5

// Actuator instance
Actuator actuator(MOTOR_PUSH_PIN, MOTOR_PULL_PIN, global_state.actuator_max_pwm_distance, &global_state);

void setup() {
    Serial.begin(115200); // serial communication at 115200
    pinMode(MOTOR_PUSH_PIN, OUTPUT);
    pinMode(MOTOR_PULL_PIN, OUTPUT);

    // Directly setting the state of the actuator to PULL
    digitalWrite(MOTOR_PUSH_PIN, LOW); // Ensure push is deactivated.
    digitalWrite(MOTOR_PULL_PIN, HIGH); // Activate pull.
    Serial.println("Actuator set to PULL");
    

    // Additionally setting the state of the actuator to Push 
    //digitalWrite(MOTOR_PUSH_PIN, HIGH); // Activate push
    //digitalWrite(MOTOR_PULL_PIN, LOW); // Ensure pull is deactivated
    //Serial.println("Actuator set to PUSH");
    
}

void loop() {
    
    delay(10000); // Delay to keep the loop from spinning too fast.
}
