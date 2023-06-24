/*
 * FizzBuss - классическая задача для обучения детей счету. Также применяется для "тестирования" программистов.
 *
 * Описание:
 * Цикл от 1 до 100.
 * Если число делится на 3 пишем "Fizz".
 * Если число делится на 5 пишем "Buzz".
 * Если число делится на 3 и на 5 пишем "FizzBuzz"
 * Если число не делится ни на 3 ни на 5 пишем само число.
 */
#include <iostream>

// Лучшее базовое решение, на мой взгляд
void fizzbuzz_classic();

// Решение, оптимизированное по скорости
void fizzbuzz_opt_speed_wise();

// Решение, оптимизированное по памяти
void fizzbuzz_opt_memory_wise();

// Максимально быстрое решение с 1 доп. переменной
void fizzbuzz_ultra_speed();

const int numbers = 100;
const std::string fizz("Fizz");
const std::string buzz("Buzz");

int main() {
    std::cout << "=== Classic ===" << std::endl;
    fizzbuzz_classic();
    std::cout << "=== Speed wise ===" << std::endl;
    fizzbuzz_opt_speed_wise();
    std::cout << "=== Memory wise ===" << std::endl;
    fizzbuzz_opt_memory_wise();
    std::cout << "=== ULTRA! ===" << std::endl;
    fizzbuzz_ultra_speed();
}

/*
 * Базовое решение.
 * Понятно описывает исходную задачу.
 * Если скорость и использование памяти кодом устраивают, то решение должно быть таким.
 */
void fizzbuzz_classic() {
    for (auto i = 1; i <= numbers; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            std::cout << fizz << buzz;
        } else if (i % 3 == 0) {
            std::cout << fizz;
        } else if (i % 5 == 0) {
            std::cout << buzz;
        } else {
            std::cout << i;
        }
        std::cout << std::endl;
    }
}

/*
 * Оптимизация задачи по скорости с использованием дополнительной памяти.
 * Вместо четырех вычислений остатка происходит два.
 * Результат вычислений сохраняется в переменных (дополнительная память).
 */
void fizzbuzz_opt_speed_wise() {
    for (auto i = 1; i <= numbers; i++) {
        auto divisible_by_3 = i % 3 == 0;
        auto divisible_by_5 = i % 5 == 0;
        if (divisible_by_3 && divisible_by_5) {
            std::cout << fizz << buzz;
        } else if (divisible_by_3) {
            std::cout << fizz;
        } else if (divisible_by_5) {
            std::cout << buzz;
        } else {
            std::cout << i;
        }
        std::cout << std::endl;
    }
}

/*
 * Оптимизация задачи без увеличения используемой памяти.
 * (N делится на A) и (N делится на B) заменяем на (N делится на LCM(A,B)) - наименьшее общее кратное.
 * 4 вычисления остатка заменяются на 3.
 */
void fizzbuzz_opt_memory_wise() {
    for (auto i = 1; i <= numbers; i++) {
        // LCM(3,5)=15
        if (i % 15 == 0) {
            std::cout << fizz << buzz;
        } else if (i % 3 == 0) {
            std::cout << fizz;
        } else if (i % 5 == 0) {
            std::cout << buzz;
        } else {
            std::cout << i;
        }
        std::cout << std::endl;
    }
}

void fizzbuzz_ultra_speed() {
    for (auto i = 1; i <= numbers; i++) {
        // bit 1 - делимость на 3, bit 0 - делимость на 5
        auto divisibility = ((i % 3 == 0) << 1) | (i % 5 == 0);

        if (divisibility & 2) std::cout << fizz;
        if (divisibility & 1) std::cout << buzz;
        if (!divisibility) std::cout << i;
        std::cout << std::endl;
    }
}
