package util;

import java.util.List;

import entity.Grammar;



public class SetUtil {
	/**
	 * 获取终结符、非终结符的First集
	 */
	public static void getFristSet() {
		String tofile = "终结符的FIRST集：\r\n";
		// System.out.println();
		// System.out.println("终结符的FIRST集：");
		for (String key : MyUtil.terminalSymbolMap.keySet()) {
			MyUtil.terminalSymbolMap.get(key).getFirst().add(key);
			List<String> terminalfirst = MyUtil.terminalSymbolMap.get(key)
					.getFirst();
			tofile = tofile + "FIRST(" + key + ") = " + terminalfirst + "\r\n";
			// System.out.println("FIRST(" + key + ") = " + terminalfirst);
		}
		tofile = tofile + "\r\n非终结符的FIRST集：\r\n";
		// System.out.println();
		// System.out.println("非终结符的FIRST集：");
		for (String key : MyUtil.nonTerminalSymbolMap.keySet()) {
			List<String> nonTerminalfirst = MyUtil
					.FIRST(MyUtil.nonTerminalSymbolMap.get(key));
			MyUtil.nonTerminalSymbolMap.get(key).setFirst(nonTerminalfirst);
			tofile = tofile + "FIRST(" + key + ") = " + nonTerminalfirst
					+ "\r\n";
			// System.out.println("FIRST(" + key + ") = " + nonTerminalfirst);
		}
		FileUtil.WriteFile(tofile, "FirstSet.txt");
		// System.out.println();
	}
	
	/**
	 * 获取非终结符的Follow集
	 */
	public static void getFollowSet() {
		String tofile = "非终结符的FOLLOW集:\r\n";
		// System.out.println("非终结符的FOLLOW集：");
		MyUtil.nonTerminalSymbolMap
				.get(MyUtil.grammarList.get(0).getLeftPart()).getFollowList()
				.add("#");
		MyUtil.whetherChanged = true;
		while (MyUtil.whetherChanged) {
			MyUtil.whetherChanged = false;
			MyUtil.FOLLOW();
		}
		for (String key : MyUtil.nonTerminalSymbolMap.keySet()) {
			List<String> mfollow = MyUtil.nonTerminalSymbolMap.get(key)
					.getFollowList();
			tofile = tofile + "FOLLOW(" + key + ") = " + mfollow + "\r\n";
			// System.out.println("FOLLOW(" + key + ") = " + mfollow);
		}
		// System.out.println();
		FileUtil.WriteFile(tofile, "FollowSet.txt");
	}
	/**
	 * 获取非终结符Select集
	 */
	public static void getSelectSet() {
		String tofile = "文法表达式的SELECT集：\r\n";
		// System.out.println("文法表达式的SELECT集：");
		for (int i = 0; i < MyUtil.grammarList.size(); i++) {
			Grammar grammar = MyUtil.grammarList.get(i);
			List<String> mselect = MyUtil.SELECT(grammar);
			if (mselect != null) {
				for (String str : mselect) {
					grammar.getSelect().add(str);
				}
			}
			tofile = tofile + "SELECT(" + grammar.getmGrammar() + ") = "
					+ grammar.getSelect() + "\r\n";
			// System.out.println("SELECT(" + grammar.getmGrammar() + ") = "+
			// grammar.getSelect());
		}
		// System.out.println();
		FileUtil.WriteFile(tofile, "SelectSet.txt");
	}
	
}
