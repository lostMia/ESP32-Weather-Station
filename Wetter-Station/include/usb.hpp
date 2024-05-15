/*
 * @file usb.hpp
 * @authors lostmia
 * @brief 
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/

#pragma once

// REMOVE TO DISABLE DEBUG MESSAGES!
#define DEBUG

#ifdef DEBUG
#define DEBUG_MESSAGE(message) Serial.printf("Error!\n %s", message);
#else
#define DEBUG_MESSAGE 
#endif