package org.example;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;

public class StringHtmlCleaner {
    public static String cleanHtml(String html) {
        Document doc = Jsoup.parse(html);
        return doc.text();
    }
}