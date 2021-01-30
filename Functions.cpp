int32_t sumOfDigits(int n, int sum)
{
    if (n == 0) return sum;
    return sumOfDigits(n/10, sum + (n%10));
}

void reverseOfDigits(int n)
{
    if (n % 10 == 0) return;
    std::cout << n%10 << "\t";
    return reverseOfDigits(n/10);
}

bool isPrime(int32_t n, int32_t now) { // here 2 is not a prime number (divides in 2) 
   if (!(n % now)) return false;
   if (now <= sqrt(n)) return isPrime(n, now+1);
   return true;
} 

/**
* Hanoi solution finder (for 3 pins)
* param i: start pin number
* param k: finish pin number
* param n: number of disks
**/

// 6 = 1 + 2 + 3(nums if pins)

void hanoiTowers(int i, int k, int n)
{
   if (n == 1)
   {
       std::cout << "Move disk 1 from pin " << i << " to " << k << "\n";
       return;
   }
   else
   {
       hanoiTowers(i, 6 - i - k, n - 1);
       std::cout << "Move disk " << n << " from pin " << i << " to " << k << "\n";
       hanoiTowers(6 - i - k, k, n - 1);
   }
}


void multipliers(int32_t n, int32_t now, float lim)
{
    if (n % now == 0)
    {
        std::cout << now << "\t";
        return multipliers(n/now, now, lim);
    }
    if (now > lim) return;
    return multipliers(n, now+1, lim);
}

int permutation[n]; // array for permutations
bool used[n] = false;

void permutations(int16_t len, int16_t idx, int16_t permutation[], bool used[])
{
    if (idx == len)
    {
        for (int i = 0; i < len; i++) std::cout << permutation[i];
        std::cout << std::endl;
        return;
    }
    for (int i = 1; i <= len; i++)
    {
        if (!used[i])
        {
            permutation[idx] = i;
            used[i] = true;
            permutations(len, idx+1, permutation, used);
            used[i] = false;
        }
        else continue;
    }
}

void bruteForce(int16_t len, int32_t left_bound, int32_t right_bound, int16_t pos, int* bruteforce)
{
    if (pos == len)
    {
        std::cout << std::endl;
        for (int i = 0; i < len; i++) std::cout << bruteforce[i] << "\t";
        return;
    }
    for (int i = left_bound; i <= right_bound; i++)
    {
        bruteforce[pos] = i;
        bruteForce(len, left_bound, right_bound, pos+1, bruteforce);
    }
}

void fastSort(int* a, int16_t left, int16_t right)
{
    if (right - left <= 1) return;
    int32_t idx = left;
    for (int i = left; i < right; i++)
    {
        if (a[i] < a[idx])
        {
            std::swap(a[i], a[idx]);
            idx++;
            i = idx;
        }
    }
    fastSort(a, left, idx);
    fastSort(a, idx+1, right);
}

void mergeSort(double* arr, int16_t arr_size)
{
    if (arr_size <= 1) return; // base  case

    int16_t middle = arr_size / 2;
    double* left = arr;
    double* right = arr + middle;
    int16_t left_size = middle;
    int16_t right_size = arr_size - left_size;

    // recursion
    mergeSort(left, left_size);
    mergeSort(right, right_size);

    // merge 2 sorted parts of array;
    double* buffer = new double[arr_size];
    int16_t left_idx = 0, right_idx = 0, idx = 0;
    while (left_idx < left_size and right_idx < right_size)
    {
        if (left[left_idx] <= right[right_idx])
        {
            // taking from left part
            buffer[idx] = left[left_idx];
            idx++;
            left_idx++;
        }
        else
        {
            // taking from right part
            buffer[idx] = right[right_idx];
            idx++;
            right_idx++;
        }
    }

    // copying left elements from the left side (if there is left something)
    while (left_idx < left_size)
    {
        buffer[idx] = left[left_idx];
        idx++;
        left_idx++;
    }
}

int binSearch (int* arr, int n, int num)
{
    int left = -1, right = n;
    while (right - left >= 2)
    {
        int mid = (right - left) / 2 + left;
        if (arr[mid] < num) left = mid;
        else if (arr[mid] == num)
        {
            if (mid-1 == left) return mid;
            else right = mid + 1;
        }
        else right = mid;
    }
    return -1;
}

    // copying left elements from the right side (if there is left something)
    while (right_idx < right_size)
    {
        buffer[idx] = right[right_idx];
        idx++;
        right_idx++;
    }

    //copying buffer into original array
    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = buffer[i];
    }
    delete[] buffer;

