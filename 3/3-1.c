//没什么意思，就给出关键部分就行了
while (low <= high && x != v[mid]) {
    if (x < v[mid])
        high = mid - 1;
    else
        low = mid - 1;
    mid = (low + high) / 2;
}
if (x == v[mid])
    return mid;