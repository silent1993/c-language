package mainclass;

import java.util.ArrayList;
import java.util.List;

import entity.Grammar;
import entity.NonTerminalSymbol;
import entity.TerminalSymbol;
import entity.Token;

import util.ExcelHandle;
import util.FileUtil;
import util.MyUtil;
import util.SetUtil;

public class SyntacticAnalysis {

	public static List<Token> tokenList = new ArrayList<Token>();

	/**
	 * 将文件中的文法可分解为多个子式的文法分解
	 */
	private void getGrammarList(List<String> list) {
		for (int i = 0; i < list.size(); i++) {
			String replaceString = list.get(i).replace('|', '@'); // replace函数使用正则表达式，'|'在正则表达式中为特殊字符，故替换�?@'

			if (replaceString.indexOf("@") != -1) {
				String[] arrStrings = replaceString.split("@");
				MyUtil.grammarList.add(new Grammar(arrStrings[0]));
				String[] expLeft = arrStrings[0].split("->");
				for (int j = 1; j < arrStrings.length; j++) {
					MyUtil.grammarList.add(new Grammar(expLeft[0] + "->"
							+ arrStrings[j]));
				}
			} else {
				MyUtil.grammarList.add(new Grammar(replaceString));
			}
		}
		/*
		 * System.out.println("文法表达式："); for (int k = 0; k <
		 * MyUtil.grammarList.size(); k++) {
		 * System.out.println(MyUtil.grammarList.get(k).getmGrammar()); }
		 * System.out.println();
		 */
	}

	/**
	 * 获取文法中的非终结符,保存到nonTerminalSymbolMap
	 */
	private String[] splitNonTerminalSymbol() {
		for (int i = 0; i < MyUtil.grammarList.size(); i++) {
			String singleGrammar = MyUtil.grammarList.get(i).getmGrammar();
			String[] part = singleGrammar.split("->");
			if (part.length == 2) {
				MyUtil.grammarList.get(i).setLeftPart(part[0]);
				String[] right = part[1].split(" ");
				MyUtil.grammarList.get(i).setRightPart(
						MyUtil.StringtoList(right)); // 将数组转换为List
				if (!MyUtil.nonTerminalSymbolMap.containsKey(part[0]))
					MyUtil.nonTerminalSymbolMap.put(part[0],
							new NonTerminalSymbol(part[0]));
			}
		}

		// System.out.println("非终结符�?);
		String[] nonTerminalSymbol = new String[MyUtil.nonTerminalSymbolMap
				.keySet().size()];
		int i = 0;
		for (String string : MyUtil.nonTerminalSymbolMap.keySet()) {
			// System.out.print(string + "\t");
			nonTerminalSymbol[i] = string;
			i++;
		}
		return nonTerminalSymbol;
	}

	/**
	 * 分隔出文法中的终结符，保存到terminalSymbolMap
	 */
	private String[] splitTerminalSymbol() {
		for (int i = 0; i < MyUtil.grammarList.size(); i++) {
			List<String> rightPart = new ArrayList<String>();
			MyUtil.combineList(rightPart, MyUtil.grammarList.get(i)
					.getRightPart());
			for (String keyString : MyUtil.nonTerminalSymbolMap.keySet()) {
				if (rightPart.contains(keyString))
					rightPart.remove(keyString);
			}
			for (int k = 0; k < rightPart.size(); k++) { // 终结符
				String mtermial = rightPart.get(k);
				if (!MyUtil.terminalSymbolMap.containsKey(mtermial)) // 空仍存在于终结符集中
					MyUtil.terminalSymbolMap.put(mtermial, new TerminalSymbol(
							mtermial));
			}
		}
		String[] terminalSymbol = new String[MyUtil.terminalSymbolMap.keySet()
				.size()];

		// System.out.println("终结符：");
		int i = 0;
		for (String string : MyUtil.terminalSymbolMap.keySet()) {
			// System.out.print(string + "\t");
			terminalSymbol[i] = string;
			i++;
		}
		return terminalSymbol;
		// System.out.println();

	}

	/**
	 * 完成预测分析法的准备工作，构造非终结符的FIRST集,FOLLOW集,SELECT集
	 */
	public static void preparationWork() {
		SyntacticAnalysis sAnalysis = new SyntacticAnalysis();
		sAnalysis.getGrammarList(FileUtil.getGrammerFromFile());
		sAnalysis.splitNonTerminalSymbol();
		sAnalysis.splitTerminalSymbol();
		SetUtil.getFristSet();
		SetUtil.getFollowSet();
		SetUtil.getSelectSet();
	}

	/**
	 * 构�?预测分析�?
	 */
	public static void getAnalysisTable() {
		getHigherNTS();
		/*
		 * System.out.println("预测分析表：\n"); for (String aString :
		 * MyUtil.nonTerminalSymbolMap.keySet()) { List<NonTerminalSymbol> list
		 * = MyUtil.nonTerminalSymbolMap.get(aString).getHigherNTS();
		 * 
		 * System.out.print(aString + ":\t\t"); for (int i = 0; i < list.size();
		 * i++) System.out.print(list.get(i).getValue() + "\t");
		 * System.out.println();
		 * 
		 * }
		 */

		for (String keyString : MyUtil.nonTerminalSymbolMap.keySet()) {
			MyUtil.SYNCH(MyUtil.nonTerminalSymbolMap.get(keyString)); // 计算同步记号�?
		}

		// System.out.println("预测分析表M");

		SyntacticAnalysis sAnalysis = new SyntacticAnalysis();

		MyUtil.getAnalysisTable();
		String[] Table = new String[MyUtil.analysisTable.keySet().size()];
		int tsnum = 0;
		for (String nts : MyUtil.analysisTable.keySet()) {
			// System.out.print(nts + "\t");
			Table[tsnum] = "";
			for (String ts : sAnalysis.splitTerminalSymbol()) {
				if (MyUtil.analysisTable.get(nts).get(ts) != null) {
					Table[tsnum] = Table[tsnum]
							+ nts
							+ "->"
							+ MyUtil.ListToString(MyUtil.analysisTable.get(nts)
									.get(ts)) + "###";
				} else {
					Table[tsnum] = Table[tsnum] + " ###";
				}

			}
			// System.out.println(Table[tsnum]);
			tsnum++;
			// System.out.println("\n");
		}
		ExcelHandle.ToExcel("MyTable.xls", Table,
				sAnalysis.splitNonTerminalSymbol(),
				sAnalysis.splitTerminalSymbol());
		// System.out.println();
	}

	public static void getToken() {
		List<String> mtoken = FileUtil.getTokenFormFile();
		for (int i = 0; i < mtoken.size(); i++) {
			String[] splitString = mtoken.get(i).split("#@#");
			Token token = new Token();
			if (splitString.length == 2) {
				token.setSyn(splitString[0].toUpperCase());
				if (splitString[1].equals("$")) {
					token.setValue(splitString[0].toUpperCase());
				} else {
					token.setValue(splitString[1]);
				}
				tokenList.add(token);
			}
		}
	}


	public static List<String> getSentence() {
		List<String> sentence = new ArrayList<String>();
		for (int i = 0; i < tokenList.size(); i++) {
			sentence.add(tokenList.get(i).getSyn());
		}
		sentence.add("#");
		return sentence;
	}

	/**
	 * 获取高层结构的集�?
	 */
	public static void getHigherNTS() {
		MyUtil.whetherChanged = true;
		while (MyUtil.whetherChanged) {
			MyUtil.whetherChanged = false;
			MyUtil.calcHigherGroup();
		}
	}

	public static void GetSyntacticAnalysis() {
		preparationWork();
		getToken();

		List<String> sentence = getSentence();

		if (MyUtil.isLL1()) { // 判断文法是否为LL(1)文法
			getAnalysisTable();
			// System.out.println("待分析的句子�? + MyUtil.ListToString(sentence) + "\n");
			System.out.println("语法分析结果:");
			MyUtil.myParser(sentence);
		} else {
			System.out.println("该文法不是LL(1)文法");
		}
	}
}
