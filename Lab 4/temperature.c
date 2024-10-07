#include <stdio.h>

void categorize_temperature(float temp, int scale);

int celsius(float temp, int choice2) {
    float converted_temp;
    if (choice2 == 2) {
        converted_temp = (9.0 / 5.0) * temp + 32;
        printf("Converted temperature: %.2f°F\n", converted_temp);
        categorize_temperature(converted_temp, 2);
    } else if (choice2 == 3) {
        converted_temp = temp + 273.15;
        printf("Converted temperature: %.2fK\n", converted_temp);
        categorize_temperature(converted_temp, 3);
    } else {
        printf("Invalid input, try again\n");
        return 0;
    }
    return 0;
}

int fahrenheit(float temp, int choice2) {
    float converted_temp;
    if (choice2 == 1) {
        converted_temp = (5.0 / 9.0) * (temp - 32);
        printf("Converted temperature: %.2f°C\n", converted_temp);
        categorize_temperature(converted_temp, 1);
    } else if (choice2 == 3) {
        converted_temp = ((5.0 / 9.0) * (temp - 32)) + 273.15;
        printf("Converted temperature: %.2fK\n", converted_temp);
        categorize_temperature(converted_temp, 3);
    } else {
        printf("Invalid input, try again\n");
        return 0;
    }
    return 0;
}

int kelvin(float temp, int choice2) {
    float converted_temp;
    if (choice2 == 1) {
        converted_temp = temp - 273.15;
        printf("Converted temperature: %.2f°C\n", converted_temp);
        categorize_temperature(converted_temp, 1);
    } else if (choice2 == 2) {
        converted_temp = (9.0 / 5.0) * (temp - 273.15) + 32;
        printf("Converted temperature: %.2f°F\n", converted_temp);
        categorize_temperature(converted_temp, 2);
    } else {
        printf("Invalid input, try again\n");
        return 0;
    }
    return 0;
}

void categorize_temperature(float temp, int scale) {
    float celsius_temp = temp;
    if (scale == 2) {  
        celsius_temp = (5.0 / 9.0) * (temp - 32);
    } else if (scale == 3) {  
        celsius_temp = temp - 273.15;
    }

    if (celsius_temp < 0) {
        printf("Temperature category: Freezing\nWeather advisory: Stay indoors or wear heavy winter gear.\n");
    } else if (celsius_temp >= 0 && celsius_temp < 10) {
        printf("Temperature category: Cold\nWeather advisory: Wear a jacket.\n");
    } else if (celsius_temp >= 10 && celsius_temp < 25) {
        printf("Temperature category: Comfortable\nWeather advisory: You should feel comfortable.\n");
    } else if (celsius_temp >= 25 && celsius_temp < 35) {
        printf("Temperature category: Hot\nWeather advisory: Stay hydrated and wear light clothing.\n");
    } else {
        printf("Temperature category: Extreme Heat\nWeather advisory: Stay indoors and stay cool.\n");
    }
}

int main() {
    float temp;
    int choice1;
    int choice2;

    printf("Enter the temperature: ");
    scanf("%f", &temp);

    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &choice1);

    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &choice2);

    if (choice1 == 1) {
        celsius(temp, choice2);
    } else if (choice1 == 2) {
        fahrenheit(temp, choice2);
    } else if (choice1 == 3) {
        kelvin(temp, choice2);
    } else {
        printf("Invalid input, try again\n");
        return main();
    }

    return 0;
}
