// System Sizer II
// by N. T. Crotser
// Licensed under GNU GPLv3
// Don't be bogus, be excellent to each other, and party on dudes!
// If you found this program helpful, it'd be cool if you threw a couple kopeks my way...

#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <limits>

void toLower(char* str) {
    for (int i = 0; str[i]; ++i)
        str[i] = std::tolower(str[i]);
}

void printCentered(const char* text, int width = 80) {
    int len = std::strlen(text);
    int pad = (width - len) / 2;
    if (pad < 0) pad = 0;
    for (int i = 0; i < pad; ++i) putchar(' ');
    printf("%s\n", text);
}

int main() {
    char choice = 'n';

    do {
        printf("\n");
        printCentered("=== System Sizer II ===");
        printCentered("version 0.5");
        printCentered("=== by N. T. Crotser - ntc@crotser.us ===");
        printf("\n\n");
        printCentered("Note: In order to use this program, you MUST have a current");
        printCentered("water analysis with at least Hardness, Iron, and Manganese"); // Please do!
        printCentered("levels, otherwise don't even bother.\n");
        printCentered("If you do, you're going to have a bad time.\n\n"); 

        double hardness = 0.0, iron = 0.0, manganese = 0.0;
        int people = 0;
        char usingEcomixInput[16];
        bool usingEcomix = false;

        printf("Enter raw water hardness (gpg): ");
        scanf("%lf", &hardness);

        printf("Enter Ferric Iron level (ppm): ");
        scanf("%lf", &iron);

        printf("Enter Manganese level (ppm): ");
        scanf("%lf", &manganese);

        printf("Enter number of persons in the home: ");
        scanf("%d", &people);

// Ecomix-C has different compensation and capacity maths that must be done! 
// Y'know, for accuracy's sake.
        printf("Are you using Ecosoft ECOMIX® C media? (yes/no): ");
        scanf("%s", usingEcomixInput);
        toLower(usingEcomixInput);

        usingEcomix = (strcmp(usingEcomixInput, "yes") == 0 || strcmp(usingEcomixInput, "y") == 0);

        
// These compensation factors were given to me from a real live human working for Ecosoft, which was cool, I got to call Ukraine.
        double ironFactor = usingEcomix ? 4.0 : 5.0;
        double manganeseFactor = usingEcomix ? 5.0 : 10.0;

        double compensatedHardness = hardness + (iron * ironFactor) + (manganese * manganeseFactor);

// Value of gallonsPerPersonPerDay is provided by the U. S. EPA and is accurate as of March 24, 2025.  8647.      
        double gallonsPerPersonPerDay = 82.0;
        double dailyGallons = people * gallonsPerPersonPerDay;
        double dailyGrainRequirement = dailyGallons * compensatedHardness;
        double weeklyGrainRequirement = dailyGrainRequirement * 7;

// Compensate grain capacity while using Ecomix-C, again directly from Ecosoft.
        const double resinGrainCapacityPerCubicFoot = usingEcomix ? 20000.0 : 32000.0;


// I needed an LLM to explain to me how to do this math down here in code as I'm self taught with plenty of gaps in my knowledge.
// It all seems to work correctly, so the LLM was able to teach me how to do this for the future.

        double recommendedCubicFeet = weeklyGrainRequirement / resinGrainCapacityPerCubicFoot;
        double roundedCubicFeet = std::ceil(recommendedCubicFeet * 2.0) / 2.0;
        double recommendedGrainCapacity = roundedCubicFeet * resinGrainCapacityPerCubicFoot;

        double estimatedCapacityGallons = recommendedGrainCapacity / compensatedHardness;

        printf("\n\n=== System Sizer II Results ===\n");
        // printf("Estimated daily grain requirement: %.2f grains\n", dailyGrainRequirement); // Information overload?
        // printf("Estimated weekly grain requirement: %.2f grains\n", weeklyGrainRequirement); // Information overload?
        printf("Recommended resin volume: %.1f cubic feet\n", roundedCubicFeet);
        printf("Recommended softener size: %.0f grains\n", recommendedGrainCapacity);
        printf("Estimated capacity before regeneration: %.0f gallons\n\n", estimatedCapacityGallons);

       // printf("\nNote: Based on a 7-day regeneration cycle.\n");
        printf("\nNote: System Sizer II is a work in progress, miscalculations can occur!\n\n");

        printf("\nPress Q to quit System Sizer II.\nPress N to begin again.\n"); // Finnigan

        // Clear input buffer, how did I forget?
        while ((getchar()) != '\n');

        choice = getchar();
        choice = std::tolower(choice);

    } while (choice == 'n');

    printf("Exiting System Sizer II. Goodbye!\n"); // Say "Goodbye!" like the AOL dude.
    return 0;
}
