# https://contest.yandex.ru/contest/74964/problems/A/

import array

with open("input.txt") as f:
    f.readline()
    people_per_group = [
        (n, v) for n,v in 
            sorted(
                enumerate([int(i) for i in f.readline().split()],
                start=1,
            ),
            key=lambda v : v[1]
            )
        ]

    computers_per_room = [
        (n, v-1) for n,v in 
            sorted(
                enumerate([int(i) for i in f.readline().split()],
                start=1,
            ),
            key=lambda v : v[1]
            )
        ]

res = array.array('i', [0] * len(people_per_group))
res_qty = 0

i = 0
while i < len(computers_per_room):
    try:
        group_order, group_num = people_per_group.pop(0)
    except IndexError:
        break
    room, computers = computers_per_room[i]
    while group_num > computers:
        i+=1
        try:
            room, computers = computers_per_room[i]
        except IndexError:
            break
        

    if group_num <= computers:
        res[group_order-1] = room
        res_qty += 1
    i += 1

with open("output.txt", "w") as f:
    f.write(f"{res_qty}\n{' '.join(str(i) for i in res)}")
    

# всем в группе хватило места 
# в кажой аудитории должно быть: 
#   - на всех учащихся + ОДИН НА УЧИТЕЛЯ
# нужно отфильтровать:
#    - группы, где СЛИШКОМ МНОГО учеников
#    - аудитории, где СЛИШКОМ МАЛО компьютеров

# максимально 1000
