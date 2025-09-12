import java.util.Random;

public class QuickSortInPlace {
    private static final Random rng = new Random();

    public static void qsort(int[] a, int l, int r) {
        if (l >= r) return;
        int mid = a[l + rng.nextInt(r - l + 1)];
        int i = l, j = r;
        while (i <= j) {
            while (a[i] < mid) i++;
            while (a[j] > mid) j--;
            if (i <= j) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                i++;
                j--;
            }
        }
        qsort(a, l, j);
        qsort(a, i, r);
    }
}