package entity;
import java.util.ArrayList;
import java.util.List;

public class Grammar {

	private String theGrammar;
	private String left;
	private List<String> right;
	private List<String> select;

	public Grammar(String theGrammer) {
		this.theGrammar = theGrammer;
		this.select = new ArrayList<String>();
		this.right = new ArrayList<String>();
	}

	public String getmGrammar() {
		return theGrammar;
	}

	public void setmGrammar(String theGrammar) {
		this.theGrammar = theGrammar;
	}

	public String getLeftPart() {
		return left;
	}

	public void setLeftPart(String left) {
		this.left = left;
	}

	public List<String> getRightPart() {
		return right;
	}

	public void setRightPart(List<String> right) {
		this.right = right;
	}

	public List<String> getSelect() {
		return select;
	}

	public void setSelect(List<String> select) {
		this.select = select;
	}

}
