import numpy as np
from multiprocessing import Process


def increase_by_one(array):
    array += 1


data = np.ones((100, 1))

t = Process(target=increase_by_one, args=(data,))

t.start()
t.join()

print(data[0])

# What you see in the code above is very subtle, but very important also.
# Data was defined on the main thread and is passed as an argument to the thread.
# Inside the thread, the data gets modified, but that is happening to the data on the main thread.
# This basically means that the data on the main thread and the data on the child thread is actually the same.
