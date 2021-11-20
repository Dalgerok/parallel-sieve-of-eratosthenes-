import os
import time
import sys
from prettytable import PrettyTable

os.system("make > /dev/null")


soe_names = ["soe", "soe_odd_only",
"soe_odd_only_blockwise", "soe_odd_only_blockwise_sqrt"]

rows = [' ']
for soe_name in soe_names[:2]:
    rows.append(soe_name)
    rows.append(soe_name + " P")
t = PrettyTable(rows)

cur_power = 6
N = 10**cur_power

while cur_power <= 11:
    times = ["10^{}".format(cur_power)]
    for soe_name in soe_names[:2]:
        start = time.time()
        if os.system("./main {} {} > /dev/null".format(soe_name, N)):
            times.append("MEM")
        else:
            times.append(round(time.time() - start, 2))
        start = time.time()
        if os.system("./main {} {} {} > /dev/null".format(soe_name, N, "P")):
            times.append("MEM")
        else:
            times.append(round(time.time() - start, 2))
    t.add_row(times)
    N *= 10
    cur_power += 1
print(t)

os.system("make clean > /dev/null")
