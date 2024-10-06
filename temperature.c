#include <stdio.h>

float celsius_to_fahrenheit(float celsius);     //all functions
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit); 
void categorize_temperature(float celsius);

int main() {
    float temperature, converted_temp;
    int current_scale, target_scale;
    
    printf("Enter the temperature: ");
    scanf("%f", &temperature);
    
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &current_scale);
    
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &target_scale);
    
    if (current_scale == 1 && target_scale == 2) {       //temp conversions
        converted_temp = celsius_to_fahrenheit(temperature);
    } else if (current_scale == 2 && target_scale == 1) {
        converted_temp = fahrenheit_to_celsius(temperature);
    } else if (current_scale == 1 && target_scale == 3) {
        converted_temp = celsius_to_kelvin(temperature);
    } else if (current_scale == 3 && target_scale == 1) {
        converted_temp = kelvin_to_celsius(temperature);
    } else if (current_scale == 2 && target_scale == 3) { 
        converted_temp = fahrenheit_to_kelvin(temperature);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    printf("Converted temperature: %.2f\n", converted_temp);
    
    float celsius_equivalent;     //categorizing Celsius equal
    if (current_scale == 1) {
        celsius_equivalent = temperature;
    } else if (current_scale == 2) {
        if (target_scale == 1) {
            celsius_equivalent = converted_temp;
        } else {
            celsius_equivalent = fahrenheit_to_celsius(temperature);
        }
    } else { 
        if (target_scale ==1) {
            celsius_equivalent = converted_temp;
        } else {
            celsius_equivalent = kelvin_to_celsius(temperature);
        }
    }
    
    categorize_temperature(celsius_equivalent);  //advisory

    return 0;
}

float celsius_to_fahrenheit(float celsius) {      //math conversions
    return (celsius * 9/5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {   
    return (fahrenheit - 32) * 5/9 + 273.15;
}

void categorize_temperature(float celsius) {    //temp categories
    if (celsius < -10) {
        printf("Temperature category: Freezing\nWeather advisory: Wear heavy winter clothing.\n");
    } else if (celsius >= -10 && celsius < 0) {
        printf("Temperature category: Cold\nWeather advisory: Wear a jacket.\n");
    } else if (celsius >= 0 && celsius <= 30) { // Adjusted upper limit for "Comfortable"
        printf("Temperature category: Comfortable\nWeather advisory: You should feel comfortable.\n");
    } else if (celsius > 30 && celsius < 35) {
        printf("Temperature category: Hot\nWeather advisory: Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\nWeather advisory: Stay indoors and cool.\n");
    }
}
