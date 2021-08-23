#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <gmp.h>

/**
 * Calcuates the nth fibonacci number.
 * Index starts from 0.
 * Result will be stored in the mpz_t passed
 *
 * @param n Which fibonacci number you want
 * @param ret The mpz_t which will be assigned
 *
 * @return void
 */
void Fibonacci(size_t n, mpz_t *ret);

/**
 * Calcuates the nth fibonacci number, without using previously calculated variables.
 * Index starts from 0.
 * Result will be stored in the mpz_t passed
 *
 * @param n Which fibonacci number you want
 * @param ret The mpz_t which will be assigned
 *
 * @return void
 */
void FibonacciStart(size_t n, mpz_t *ret);

/**
 * Calcuates the nth fibonacci number, from previously calculated number
 * Index starts from 0.
 * Result will be stored in the mpz_t passed
 *
 * @param n Which fibonacci number you want
 * @param ret The mpz_t which will be assigned
 *
 * @return void
 */
void FibonacciContinue(size_t n, mpz_t *ret);

/**
 * Deletes all calculated values and resets the system
 */
void FibonacciFinish();

#endif
