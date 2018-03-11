# WaterTaxi

The Davos Water Taxi Company uses a boat on Georgian Bay to transport people and goods from the main dock to various islands and ports around the bay. The service charge for a trip is $11.00 for each stop and $2.70 per kilometer of travel. Some people take a full round trip back to the main dock and are therefore charged for the distance to travel back. Other people get off at the last given coordinates and are not charged for the taxi travelling back to the main dock.

A GPS records the (x, y) position for each stop. The position of the main dock is (0,0). Each leg of the trip is made in a straight line.

A file called “taxi.txt” contains the records for all the trips made in August. Each line in the file contains the information for one customer. The data on each line is formatted as follows:
- A binary (0 or 1) value that indicates whether the customer returned to the main dock or not. 1 = return trip and 0 = no return trip.
- The number of stops, not including returning to the main dock.
- Pairs of (x,y) coordinates for each of the stops.

Your program is to generate a report file summarizing the taxi’s earnings for the month of August. The report must contain the following information on each line:
- Trip number
- Return to main dock (0 = no, 1 = yes)
- Number of stops (not including return to main dock)
- Total distance travelled for the trip
- Total cost charged to the customer
- Cumulative distance travelled during the month
- Cumulative cost charged to all customers during the month
The report is to display only the lines for the first five trips and then every tenth thereafter (i.e. the 15th, 25th, etc.).

The report must also include the following data at the bottom:
- cumulative distance travelled for all of August
- cumulative amount collected from all customers for all of August
- the length of the longest trip
- the cost of the least expensive trip

