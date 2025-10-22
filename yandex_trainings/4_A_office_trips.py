# https://contest.yandex.ru/contest/80942/problems/A/

import datetime as dt

total_buses = 0

def launch_buses(
    current_time: int,
    office_trips: list[tuple[int, int]],
    available_buses: list[int],
    opposite_available_buses: list[int],
):
    global total_buses

    while office_trips and office_trips[0][0] == current_time:

        if available_buses[current_time] != 0:
            available_buses[current_time] -= 1
        else:
            total_buses += 1
        
        opposite_available_buses[office_trips[0][1]] += 1

        office_trips.pop(0)

    available_buses[current_time+1] += available_buses[current_time]



def main(first_to_second_office_trips: list[tuple[int, int]], second_to_first_office_trips: list[tuple[int, int]]) -> int:
    global total_buses
    total_buses = 0
    
    first_available_buses = [0] * (60 * 24 + 2)
    second_available_buses = [0] * (60 * 24 + 2)

    current_time = 0

    while current_time <= 60 * 24:
        launch_buses(
            current_time,
            first_to_second_office_trips,
            first_available_buses,
            second_available_buses,
        )

        launch_buses(
            current_time,
            second_to_first_office_trips,
            second_available_buses,
            first_available_buses,
        )
        current_time += 1

    return total_buses
    # print(total_buses)


if __name__ == "__main__":
    import sys
    data = sys.stdin.read().splitlines()

    first_to_second_office_trips_ = []
    
    def convert_to_seconds(t: str):
        t = dt.datetime.strptime(t, "%H:%M").time()
        return t.hour * 60 + t.minute

    for i in range(1, int(data[0]) + 1):
        departure_time, arrival_time = [
            convert_to_seconds(z) for z in data[i].split('-')
            ]

        first_to_second_office_trips_.append(
            (departure_time, arrival_time)
        )

    second_to_first_office_trips_ = []

    for i in range(int(data[0])+2, len(data)):
        departure_time, arrival_time = [
            convert_to_seconds(z) for z in data[i].split('-')
            ]

        second_to_first_office_trips_.append(
            (departure_time, arrival_time)
        )

    first_to_second_office_trips_.sort()
    second_to_first_office_trips_.sort()

    print(main(first_to_second_office_trips_, second_to_first_office_trips_))
