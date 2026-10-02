from collections import defaultdict

def display_time_portal_usage(usage_records):
    # {portal id : {time: freq}}
    portal_stats = defaultdict(lambda: defaultdict(int))
    all_times = set()

    # look at bottom of file
    # I think it works

    # find all times + frequency at times per portal
    for _, portal_id, time in usage_records:
        all_times.add(time)
        portal_stats[int(portal_id)][time] += 1

    # all times is now a sorter array of times
    all_times = list(all_times)
    all_times.sort()

    portals_sorted = sorted(portal_stats.items()) # we sort the items based on key(id) 
    # is it: list(portal_stats) so we get all the ids?
    # portal_stats.items() is [[portal id : {time: freq}], [portal id : {time: freq}], ...]
    # I think we sort portal ids too? and iteratre based on those?

    # okay let's just test with this.
    # yes plz
    # header
    res = [["Portal"]]
    res[0].extend(all_times)
    
    # add each row for each portal

    # don't we need to adjust loop first? k, rnning
    for portal_id, times_dict in portals_sorted: #already used it
        sol = [portal_id]

        for time in all_times:
            visitors = portal_stats[portal_id][time]
            sol.append(visitors)

        res.append(sol) 

    return res # want me to test it? yes!

usage_records1 = [["David","3","10:00"],
                  ["Corina","10","10:15"],
                  ["David","3","10:30"],
                  ["Carla","5","11:00"],
                  ["Carla","5","10:00"],
                  ["Rous","3","10:00"]]
usage_records2 = [["James","12","11:00"],
                  ["Ratesh","12","11:00"],
                  ["Amadeus","12","11:00"],
                  ["Adam","1","09:00"],
                  ["Brianna","1","09:00"]]
usage_records3 = [["Laura","2","08:00"],
                  ["Jhon","2","08:15"],
                  ["Melissa","2","08:30"]]

print(display_time_portal_usage(usage_records1))
print(display_time_portal_usage(usage_records2))
print(display_time_portal_usage(usage_records3))


# Expected:
# [['Portal','10:00','10:15','10:30','11:00'],['3','2','0','1','0'],['5','1','0','0','1'], ['10','0','1','0','0']]
# [['Portal','09:00','11:00'],['1','2','0'],['12','0','3']]
# [['Portal','08:00','08:15','08:30'],['2','1','1','1']]

# output: 
# [['Portal', '10:00', '10:15', '10:30', '11:00'], [3, 2, 0, 1, 0], [5, 1, 0,0, 1], [10, 0, 1, 0, 0]]
# [['Portal', '09:00', '11:00'], [1, 2, 0], [12, 0, 3]]
# [['Portal', '08:00', '08:15', '08:30'], [2, 1, 1, 1]]

# nice it finally works (leetcode medium btw)

# alr, cya man

# cheers