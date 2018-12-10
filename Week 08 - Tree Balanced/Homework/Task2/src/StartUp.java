import java.util.Scanner;
import java.util.TreeMap;

public class StartUp {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        TreeMap<Integer, Integer> friends = new TreeMap<>();

        int m = scanner.nextInt();
        int n = scanner.nextInt();

        friends.put(m, -1);

        for (int i = 0; i < n; i++) {

            int first = scanner.nextInt();
            int second = scanner.nextInt();

            if (friends.containsKey(first)){
                friends.put(first, second);
                friends.put(second, -1);
            }
        }

        System.out.println(friends.size());

    }

}