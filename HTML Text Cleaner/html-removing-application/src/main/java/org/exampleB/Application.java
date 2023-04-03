package org.exampleB;
public class Application {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.err.println("Usage: java App <url>");
            System.exit(1);
        }

        String url = args[0];
        String html = org.example.PageDownloadingUtility.download(url);
        String cleaned = org.example.StringHtmlCleaner.cleanHtml(html);

        System.out.println(cleaned);
    }
}


// ./gradlew :html-removing-application:run --args="http://www.kssk.pwr.edu.pl"