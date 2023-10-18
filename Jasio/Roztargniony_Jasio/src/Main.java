import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static int numberOfBreaks = 0;

    public static void DFS(int v, List<Integer> listOne, List<Integer> listTwo, int pom) {
        listTwo.set(v, pom);
        if (listTwo.get(listOne.get(v)) == -1)
            DFS(listOne.get(v), listOne, listTwo, pom);
        else if (listTwo.get(listOne.get(v)) == pom)
            numberOfBreaks++;
    }

    public static void main(String[] args) {
        String fileName = "test2.txt"; // Nazwa pliku do odczytu
        int numberOfBanks = 0;
        int numberPom = 0;
        List<Integer> edge = new ArrayList<>();
        List<Integer> edgePom = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            numberOfBanks = Integer.parseInt(br.readLine()); // Pobieranie ilości skarbonek

            for (int i = 0; i <= numberOfBanks; i++) { //inicjalizacja grafu
                edge.add(0);
                edgePom.add(-1);
            }

            for (int i = 0; i < numberOfBanks; i++) { //zapelnianie grafu
                edge.set(i + 1, Integer.parseInt(br.readLine()));
            }
        } catch (IOException e) {
            System.out.println("Błąd odczytu pliku: " + e.getMessage());
        }

        for (int i = 1; i <= numberOfBanks; i++) {
            if (edgePom.get(i) == -1) {
                DFS(i, edge, edgePom, numberPom);
                numberPom++;
            }
        }

        System.out.println("Minimalnie nalezy zbic : " + numberOfBreaks + " skarbonek");
    }
}
