package util;

import java.util.List;

import entity.Grammar;



public class SetUtil {
	/**
	 * ��ȡ�ս�������ս����First��
	 */
	public static void getFristSet() {
		String tofile = "�ս����FIRST����\r\n";
		// System.out.println();
		// System.out.println("�ս����FIRST����");
		for (String key : MyUtil.terminalSymbolMap.keySet()) {
			MyUtil.terminalSymbolMap.get(key).getFirst().add(key);
			List<String> terminalfirst = MyUtil.terminalSymbolMap.get(key)
					.getFirst();
			tofile = tofile + "FIRST(" + key + ") = " + terminalfirst + "\r\n";
			// System.out.println("FIRST(" + key + ") = " + terminalfirst);
		}
		tofile = tofile + "\r\n���ս����FIRST����\r\n";
		// System.out.println();
		// System.out.println("���ս����FIRST����");
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
	 * ��ȡ���ս����Follow��
	 */
	public static void getFollowSet() {
		String tofile = "���ս����FOLLOW��:\r\n";
		// System.out.println("���ս����FOLLOW����");
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
	 * ��ȡ���ս��Select��
	 */
	public static void getSelectSet() {
		String tofile = "�ķ����ʽ��SELECT����\r\n";
		// System.out.println("�ķ����ʽ��SELECT����");
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
