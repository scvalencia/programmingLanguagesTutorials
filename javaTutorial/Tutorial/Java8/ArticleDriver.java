import java.util.*;
import java.util.stream.*;

public class ArticleDriver {

	public static ArrayList<Article> articles;

	public static void main(String[] args) {
		articles = new ArrayList<Article>();
		// sequential version
		Stream<Article> articlesStream = articles.stream();
		 
		//parallel version 
		Stream<Article> articlesParallelStream = articles.parallelStream();
		
		populate();

		Optional<Article> firstArticleOnComputing = getFirstComputerArticles();

		List<Article> compilerArticles = filterArticles("Compiler");

		for(Article a : compilerArticles)
			System.out.println(a);

		List<Article> computerArticles = filterArticles("Computers");

		for(Article a : computerArticles)
			System.out.println(a);

		Set<String> tags = getDistinctTags();

		for(String tag : tags)
			System.out.println(tag);

		articles.forEach(a -> a.setId(4));

		for(Article a : articles)
			System.out.println(a.id);

		Stream<Article> brianKernighanRules = articles.stream()
			.map(a -> new Article("Why Pascal is not my favourite programming language", "Brian Kernighan", null));

		for(Article a : brianKernighanRules.collect(Collectors.toList()))
			System.out.println(a);
	}

	public static void populate() {

		List<String> tags = new ArrayList<String>();
		tags.add("Mathematics");
		tags.add("Computers");
		tags.add("Information");

		Article a = new Article("A mathematical theory of communication", "Clade Shannon", tags);
		articles.add(a);

		tags = new ArrayList<String>();
		tags.add("Mathematics");
		tags.add("Computers");
		tags.add("Logic");
		tags.add("Computation");

		a = new Article("On Computable Numbers, with an Application to the Entscheidungsproblem", "Alan Turing", tags);
		articles.add(a);

		tags = new ArrayList<String>();
		tags.add("Operating System");
		tags.add("Computers");
		tags.add("Unix");
		tags.add("C");

		a = new Article("Reflections on Trusting Trust", "Clade Shannon", tags);
		articles.add(a);

		tags = new ArrayList<String>();
		tags.add("IEEE");
		tags.add("Computers");
		tags.add("Hardware");
		tags.add("Architecture");
		tags.add("C");

		a = new Article("What Every Computer Scientist Should Know About Floating-Point Arithmetic", "David Goldberg", tags);
		articles.add(a);

		tags = new ArrayList<String>();
		tags.add("Algorithms");
		tags.add("Combinatorics");
		tags.add("Optimization");

		a = new Article("Paths, Trees and Flowers", "John Edmonds", tags);
		articles.add(a);

		tags = new ArrayList<String>();
		tags.add("Complexity");
		tags.add("Combinatorics");
		tags.add("Computation");

		a = new Article("Reducibility Among Combinatorial Problems", "Richard Karp", tags);
		articles.add(a);

		tags = new ArrayList<String>();
		tags.add("Programming Languages");
		tags.add("Functional Languages");
		tags.add("Computers");

		a = new Article("Call-by-value is dual to call-by-name", "Philip Wadler", tags);
		articles.add(a);

		tags = new ArrayList<String>();
		tags.add("Programming");
		tags.add("Algorithms");
		tags.add("Verification");

		a = new Article("An Axiomatic Basis for Computer Programming", "C.A.R. Hoare", tags);
		articles.add(a);

	}

	/*
	* We first use the filter operation to find all articles that have the Java tag, 
	* then used the findFirst() operation to get the first occurrence. Since streams 
	* are lazy and filter returns a stream, this approach only processes elements until 
	* it finds the first match.
	*/

	public static Optional<Article> getFirstComputerArticles() {
		return articles.stream()
			.filter(article -> article.getTags().contains("Computers"))
			.findFirst();
	}

	/*
	* In this example we used the collect operation to perform a reduction on 
	* the result stream instead of declaring a collection ourselves and explicitly 
	* add the articles if they match.
	*/

	public static List<Article> filterArticles(String tag) {  
	    return articles.stream()
	        .filter(article -> article.getTags().contains(tag))
	        .collect(Collectors.toList());
    }

    public static Map<String, List<Article>> groupByAuthor() {  
	    return articles.stream()
	        .collect(Collectors.groupingBy(Article::getAuthor));
	}

	public static Set<String> getDistinctTags() {  
	    return articles.stream()
	        .flatMap(article -> article.getTags().stream())
	        .collect(Collectors.toSet());
	}

}

class Article {

	public int id;
    public String title;
    public String author;
    public List<String> tags;

    public Article(String title, String author, List<String> tags) {
        this.title = title;
        this.author = author;
        this.tags = tags;
    }

    public void setId(int nid) {
    	this.id = nid;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public List<String> getTags() {
        return tags;
    }

    public String toString() {
    	return this.title;
    }
}