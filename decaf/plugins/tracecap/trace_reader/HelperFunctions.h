/**
 * @file Some generic functions.
 * @Author Lok Yan
 */
#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <string>
#include <inttypes.h>

/**
 * Converts a single hex char into a nibble.
 * @param c The hex char
 * @return 0xFF if c was not a hex char
 * @return 0x0X where X is the corresponding hex value.
 */
uint8_t hexCharToNibble(char c);

/**
 * Converts two hex characters into a single byte.
 * @param h Reference to the byte to put the result in.
 * @param c1 The high order character
 * @param c2 The low order character
 * @return 0 If successful
 * @return -1 If not.
 */
int hexCharsToByte(uint8_t& h, char c1, char c2);

/**
 * Converts a hex string into an unsigned long. Calls myHexStrToul(..., const char*);
 */
int myHexStrToul(uint32_t& ul, const std::string& str);

/**
 * Converts a hex string into an unsigned long. Calls myHexStrToBArray. This function differs from the stdc one because:
 * 1. strtoul converts 0x12345678a (the a is ignored), this returns -1
 * 2. strtoul converts 0x12345678 a (the ' ' and a are ignored), this returns 2
 */
int myHexStrToul(uint32_t& ul, const char* str);

/**
 * Converts the hex string into a byte array.
 * @param pul Reference to the pointer that will contain the array. If it is NULL, then a new array will be created - MUST BE DELETED.
 * @param count The length of the array pointed to by pul. It will contain the number of bytes successfully converted.
 * @param str Pointer to the string.
 * @return 0 If wholly successful
 * @return 1 If the hex string ends with whitespaces, e.g. "0x1234 "
 * @return 2 If the hex string ends with whitespaces followed by non whitespaces, e.g. "0x1234 5"
 * @return -1 If conversion failed
 * @return -2 If there is nothing to convert
 */
int myHexStrToBArray( uint8_t*& pul, size_t& count, const char* str);

/**
 * Converts the hex string into a byte array. Calls myHexStrToBArray(..., const char*)
 */
int myHexStrToBArray( uint8_t*& pul, size_t& count, const std::string& str);
#endif//HELPERFUNCTIONS_H
