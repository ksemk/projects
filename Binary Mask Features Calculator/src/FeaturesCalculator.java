import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class FeaturesCalculator {

    private ArrayList<ArrayList<Integer>> binary_mask;
    private Integer[] mass_center;
    private String filename;

    public FeaturesCalculator(String filename) {
        this.filename = filename;
        this.binary_mask = new ArrayList<>();
        this.mass_center = new Integer[]{0, 0};
    }

    public void read_data() {
        try {
            Scanner scanner = new Scanner(new File(filename));
            while (scanner.hasNextLine()) {
                String[] row = scanner.nextLine().trim().split(" ");
                ArrayList<Integer> binary_row = new ArrayList<>();
                for (String element : row) {
                    binary_row.add(Integer.parseInt(element));
                }
                binary_mask.add(binary_row);
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }

    public void calculate_mass_center() {
        int m = binary_mask.size();
        int n = binary_mask.get(0).size();
        int mass_sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int mass = binary_mask.get(i).get(j);
                mass_sum += mass;
                mass_center[0] += j * mass;
                mass_center[1] += i * mass;
            }
        }
        mass_center[0] /= mass_sum;
        mass_center[1] /= mass_sum;
    }

    public void save_results() {
        try {
            FileWriter writer = new FileWriter(new File(filename.replace(".txt", " out.txt")));
            for (int i = 0; i < binary_mask.size(); i++) {
                for (int j = 0; j < binary_mask.get(i).size(); j++) {
                    if (i == mass_center[1] && j == mass_center[0]) {
                        writer.write("P ");
                    } else {
                        writer.write(binary_mask.get(i).get(j) + " ");
                    }
                }
                writer.write("\n");
            }
            writer.close();
        } catch (IOException e) {
            System.out.println("Error saving file: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the filename: ");
        String filename = scanner.nextLine();
        scanner.close();

        FeaturesCalculator calculator = new FeaturesCalculator(filename);
        calculator.read_data();
        calculator.calculate_mass_center();
        calculator.save_results();
    }
}
