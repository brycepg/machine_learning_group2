import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import matplotlib.lines as mlines
import sys # for maxint
from numpy import arange
import numpy as np

data_point_file = open('data_n_assignments.csv', 'r')


# Used to plot the centroids
centroid_x = []
centroid_y = []

centroid_file = open('centroids.csv')
centroid_count = 0

for line in centroid_file:
    splitline = line.split(',')
    centroid_x.append(splitline[0])
    centroid_y.append(splitline[1])
    centroid_count += 1

centroid_file.close()

# Unpack csv file into lists for plotting
x = []
y = []
# Assignment will be used for color codes
assignment = []

# Color codes only go from 0 to 9.9999 so divide if centroids are greater 
divisor = 1; 
if (centroid_count > 1):
    divisor = 1/centroid_count

# For determining graph axes. Set to non number pre init
firstline = True
minx=np.nan
maxx=np.nan
miny=np.nan
maxy=np.nan

for line in data_point_file:
    splitline = line.split(',')
    currentx = float(splitline[0])
    currenty = float(splitline[1])
    x.append(currentx)
    y.append(currenty)
    assignment.append(int(splitline[-1])/divisor)
    if currentx > maxx or firstline:
        maxx = currentx
    if currentx < minx or firstline:
        minx = currentx
    if currenty < miny or firstline:
        miny = currenty
    if currenty > maxy or firstline:
        maxy = currenty
    firstline = False;


data_point_file.close()



print("centroid count", centroid_count)
index = list(arange(0,10, divisor))
print(index)

hfont = {'fontname':'Bitstream Vera Sans'}
# Setting font, axes, labeling
plt.xticks(**hfont)
plt.yticks(**hfont)
plt.xlabel("X values", **hfont)
plt.ylabel("Y values", **hfont)
plt.title("Random Clustering Data", **hfont)

colormap="Paired"
plt.scatter(x,y,c=assignment, edgecolors='none', cmap=colormap)
plt.scatter(centroid_x, centroid_y, s=25, c=index, cmap=colormap)

# Set limits based on data and a little buffer
plt.xlim([minx - (maxx-minx)/100, maxx + (maxx-minx)/100])
plt.ylim([miny - (maxy-miny)/100, maxy + (maxy-miny)/100])


plt.show()
