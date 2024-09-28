import numpy as np 
import pandas as pd
import matplotlib.pyplot as plt

main = pd.read_csv("./mpi_out.txt")
print(main)
 
plt.plot(main["height"])
plt.savefig('main.png')
