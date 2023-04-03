import java.util.*;

public class Tour {
    private Map<String, String> countries = new HashMap<>();
    private List<String> cities = new ArrayList<>();
    private Set<String> uniqueCities = new HashSet<>();

    public Tour() {
        countries.put("Poland", "Warsaw");
        countries.put("Germany", "Berlin");
        countries.put("Czech", "Prague");
        countries.put("Austria", "Vienna");
        countries.put("Italy", "Rome");
        countries.put("France", "Paris");
        countries.put("Spain", "Madrid");
        countries.put("Portugal", "Lisbon");
        countries.put("Sweden", "Stockholm");

        cities.add("Warsaw");
        cities.add("Berlin");
        cities.add("Prague");
        cities.add("Vienna");
        cities.add("Rome");
        cities.add("Paris");
        cities.add("Madrid");
        cities.add("Lisbon");
        cities.add("Paris");
        cities.add("Rome");

        uniqueCities.addAll(cities);
    }
    public static void printCountriesAndCapitals(Map<String, String> countries) {
        for (Map.Entry<String, String> entry : countries.entrySet()) {
            System.out.println(entry.getKey() + " - " + entry.getValue());
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Tour tour = new Tour();
        printCountriesAndCapitals(tour.countries);
        System.out.println("Contains Sweden: " + tour.countries.containsKey("Sweden"));
        System.out.println("Contains Paris: " + tour.cities.contains("Paris"));
        System.out.println("Contains Rome: " + tour.uniqueCities.contains("Rome"));
        System.out.println("Number of countries: " + tour.countries.size());
        System.out.println("Number of cities visited: " + tour.cities.size());
        System.out.println("Number of unique cities visited: " + tour.uniqueCities.size());
    }
}