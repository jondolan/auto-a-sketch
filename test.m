fhx = fopen('outx2.txt', 'r');
fhy = fopen('outy2.txt', 'r');
formatSpec = '%f';
x = fscanf(fhx, formatSpec);
y = fscanf(fhy, formatSpec);
plot(x,y,'r-')
fclose(fhy);
fclose(fhx);
