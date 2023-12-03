#include <stdio.h>
#include <stdlib.h>

// Structure to hold accelerometer data
struct Accelerometer 
{
    float x;
    float y;
    float z;
};

// Structure to represent a Beacon
struct Beacon 
{
    char mac_address[18]; // MAC address is assumed to be a string of length 17 + 1 for null terminator
    struct Accelerometer accelerometer_data;
    int battery_level;
    int is_moving; // 0 for false, 1 for true (boolean representation)
};

// Function to send beacon packet and print information
void send_beacon_packet(struct Beacon *beacon)
 {
    printf("Sending beacon packet...\n");
    printf("MAC Address: %s\n", beacon->mac_address);
    printf("Accelerometer Data: X=%.2f, Y=%.2f, Z=%.2f\n", beacon->accelerometer_data.x,
           beacon->accelerometer_data.y, beacon->accelerometer_data.z);
    printf("Battery Level: %d%%\n", beacon->battery_level);
}

// Function to update accelerometer data
void update_accelerometer_data(struct Beacon *beacon) 
{
    // Simulating updating accelerometer data with random values
    beacon->accelerometer_data.x = ((float)rand() / RAND_MAX) * 2 - 1; // Range: [-1, 1]
    beacon->accelerometer_data.y = ((float)rand() / RAND_MAX) * 2 - 1; // Range: [-1, 1]
    beacon->accelerometer_data.z = ((float)rand() / RAND_MAX) * 2 - 1; // Range: [-1, 1]
}

// Function to check movement based on accelerometer data
void check_movement(struct Beacon *beacon)
 {
    float movement_threshold = 0.1; // Set a threshold for movement detection
    float total_acceleration = abs(beacon->accelerometer_data.x) +
                               abs(beacon->accelerometer_data.y) +
                               abs(beacon->accelerometer_data.z);

    if (total_acceleration > movement_threshold)
 {
        beacon->is_moving = 1; // true
 } 
  else 
{
        beacon->is_moving = 0; // false
    }
}

// Function to print movement status
void print_movement_status(struct Beacon *beacon) 
{
    if (beacon->is_moving)
   {
        printf("Beacon is currently in motion.\n");
}
 else 
{
        printf("Beacon is stationary.\n");
    }
}

int main()
 {
    struct Beacon beacon;

    // Simulate data extraction and beacon activities
    // Extracting MAC address (simulated)
    sprintf(beacon.mac_address, "%s", "00:11:22:33:44:55");

    // Simulate accelerometer data update
    update_accelerometer_data(&beacon);

    // Simulate checking movement based on accelerometer data
    check_movement(&beacon);

    // Simulate battery level (assumed to be 100 for demonstration)
    beacon.battery_level = 100;

    // Print status and send beacon packet
    print_movement_status(&beacon);
    send_beacon_packet(&beacon);

    return 0;
}
