package mainclass;
import java.io.*;
import java.util.HashMap;
import java.util.regex.*;

public class LexicalAnalyzer {
	/**
	 * 在文件中读出代码 将代码中的关键字或符号识别出来 检查是否有错误
	 */
	private static int linenum = 0;
	private static String[] MyCode = new String[1000];

	private static void writeFileByLines(String[] lines) {
		try {
			File file = new File("Word.txt");
			if (!file.exists()) {
				file.createNewFile();
			}
			FileWriter fileWritter = new FileWriter(file.getName(), false);
			BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
			for (int i = 0; i < lines.length; i++) {
				if (lines[i] != null) {
					bufferWritter.write(lines[i] + "\r\n");
				}
			}
			bufferWritter.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static String[] readFileByLines(String fileName) {
		File file = new File(fileName);
		BufferedReader reader = null;
		String[] tmpCode = new String[1000];
		try {
			reader = new BufferedReader(new FileReader(file));
			String tempString = null;
			int line = 1;
			while ((tempString = reader.readLine()) != null) {
				tmpCode[line] = tempString;
				line++;
			}
			linenum = line;
			reader.close();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if (reader != null) {
				try {
					reader.close();
				} catch (IOException e1) {
				}
			}
		}
		return tmpCode;
	}

	/*
	 * public static class SymbolTable { public String name; public int ID; }
	 */

	public static String[] GetWord() {
		int i, j, nCharlen;
		// SymbolTable a;
		String tmp;
		String[] nChar = new String[1000];
		String[] nkeys = new String[1000];
		int nkeysnum = 0;
		String TranCode = "";
		String[] AddSpace = { "[^\"][.*][\\!][.*][^\"]", "\\--", "\\%", "\\/",
				"\\*", "\\+", "\\-", ",", ";", "<=", ">=", "==", "!=", "<",
				">", "\\&\\&", "\\|\\|", "!", "=", "\\+=", "\\-=", "\\*=",
				"\\/=", "\\(", "\\)", "\\[", "\\]", "\\{", "\\}", "\\?:", "~",
				"&" };
		// ArrayList<SymbolTable> MySymbolTable = new ArrayList<SymbolTable>();
		// ArrayList<SymbolTable> MyHeadFileTable = new
		// ArrayList<SymbolTable>();
		HashMap<String, Integer> MySymbolTable = new HashMap<String, Integer>();

		MyCode=readFileByLines("MyCode.txt");
		Pattern ClearNote1 = Pattern.compile("/\\*.+\\*/$");
		Pattern ClearNote2 = Pattern.compile("//+.+");
		Pattern ClearNote3 = Pattern.compile("[\t\f\r]");
		Pattern ClearNote4 = Pattern.compile("[ ]+");
		Pattern FindKey1 = Pattern
				.compile("auto|break|case|char|const|continue|default|do|float|else|enum|extern|float|for|if|int|long|return|short|signed|sizeof|static|struct|string|switch|typedef|unsigned|union|void|while|#include|#define");
		Pattern FindKey2 = Pattern.compile("\\++|\\--|\\%|\\/|\\*|\\+|\\-");
		Pattern FindKey3 = Pattern.compile(",");
		Pattern FindKey4 = Pattern.compile(";");
		Pattern FindKey5 = Pattern.compile("<=|>=|==|!=|<|>");
		Pattern FindKey6 = Pattern.compile("\\&&|\\|\\||!");
		Pattern FindKey7 = Pattern.compile("=|\\+=|\\-=|\\*=|\\/=");
		Pattern FindKey8 = Pattern.compile("\\(|\\)|\\[|\\]|\\{|\\}");
		Pattern FindKey9 = Pattern.compile("\\?:|~|&");
		Pattern FindHeadFile = Pattern.compile("<([a-zA-Z]*[.h])>");
		Pattern FindString = Pattern.compile("\"([^\"]*)\"");
		Pattern FindIntNum = Pattern.compile("0|[1-9][0-9]*");
		Pattern FindDoubleNum = Pattern
				.compile("[1-9][0-9]*[.][0-9]+|0.[0-9]*|[1-9]+[e][1-9][0-9]+|[1-9]+[e][ ][-][ ][1-9][0-9]+|[1-9]+[e][-][1-9][0-9]+");
		Pattern FindName = Pattern.compile("[a-zA-Z].*");
		// System.out.println(MyCode[1]);
		for (i = 1; i < linenum; i++) {
			MyCode[i] = ClearNote1.matcher(MyCode[i]).replaceAll("");
			MyCode[i] = ClearNote2.matcher(MyCode[i]).replaceAll("");
			MyCode[i] = ClearNote3.matcher(MyCode[i]).replaceAll("");
			MyCode[i] = ClearNote4.matcher(MyCode[i]).replaceAll(" ");
			TranCode = TranCode + MyCode[i] + " ";
		}
		for (i = 0; i < AddSpace.length; i++) {
			TranCode = TranCode
					.replaceAll(AddSpace[i], " " + AddSpace[i] + " ");
		}
		// System.out.println(TranCode);

		Matcher matcher = FindString.matcher(TranCode);
		while (matcher.find()) {
			TranCode = TranCode.replace(matcher.group(), matcher.group()
					.replace(" ", ""));
		}
		matcher = FindHeadFile.matcher(TranCode);
		while (matcher.find()) {
			TranCode = TranCode.replace(matcher.group(), matcher.group()
					.replace(" ", ""));
		}
		matcher = FindDoubleNum.matcher(TranCode);
		while (matcher.find()) {
			TranCode = TranCode.replace(matcher.group(), matcher.group()
					.replace(" . ", ""));
		}
		
		
		// System.out.println(TranCode);
		String[] tmpChar = TranCode.split("[ ]+");
		String[] test = { "++", "--", "<=", ">=", "==", "!=", "&&", "||", "+=",
				"-=", "*=", "/=" };
		for (i = 0; i < tmpChar.length - 1; i++) {
			tmp = tmpChar[i] + tmpChar[i + 1];
			for (j = 0; j < test.length; j++) {
				if (tmp.equals(test[j])) {
					tmpChar[i] = test[j];
					tmpChar[i + 1] = null;
					break;
				}
			}
		}
		// System.out.println(tmpChar[1]);
		j = 0;
		for (i = 0; i < tmpChar.length; i++) {
			if (tmpChar[i] != null && tmpChar[i] != " ") {
				nChar[j] = tmpChar[i];
				tmpChar[i] = "";
				// System.out.println(nChar[j]);
				j++;
			}
		}
		String testChar;
		nCharlen = j;
		for (i = 0; i < nCharlen; i++) {
		//	System.out.println(nChar[i]);
			testChar = nChar[i] + "test";
			if (nChar[i] == null || testChar.equals("test")) {
				nChar[i] = null;
				// System.out.println(testChar.equals("test"));
				continue;
			}
			
			if (FindHeadFile.matcher(nChar[i]).matches()) {
				/*
				 * int p = -1; a = new SymbolTable(); a.ID = 1; a.name =
				 * nChar[i]; for (j = 0; j < MyHeadFileTable.size(); j++) { if
				 * (MyHeadFileTable.get(j).name.equals(a.name)) { p = j; } } if
				 * (p == -1) { MyHeadFileTable.add(a); p =
				 * MyHeadFileTable.indexOf(a); }
				 */
				nChar[i] = "<" + "HeadFile" + "#@#" + nChar[i] + ">";
			} else if (FindString.matcher(nChar[i]).matches()) {
				nChar[i] = "<" + "String" + "#@#" + nChar[i] + ">";
			} else if (FindKey1.matcher(nChar[i]).matches()) {
				/*
				switch (nChar[i]) {
				
				case "auto":
					nChar[i] = "101";
					break;
				case "break":
					nChar[i] = "102";
					break;
				case "case":
					nChar[i] = "103";
					break;
				case "char":
					nChar[i] = "104";
					break;
				case "const":
					nChar[i] = "105";
					break;
				case "continue":
					nChar[i] = "106";
					break;
				case "default":
					nChar[i] = "107";
					break;
				case "do":
					nChar[i] = "108";
					break;
				case "double":
					nChar[i] = "109";
					break;
				case "else":
					nChar[i] = "110";
					break;
				case "enum":
					nChar[i] = "111";
					break;
				case "extern":
					nChar[i] = "112";
					break;
				case "float":
					nChar[i] = "113";
					break;
				case "for":
					nChar[i] = "114";
					break;
				case "if":
					nChar[i] = "115";
					break;
				case "int":
					nChar[i] = "116";
					break;
				case "long":
					nChar[i] = "117";
					break;
				case "return":
					nChar[i] = "118";
					break;
				case "short":
					nChar[i] = "119";
					break;
				case "signed":
					nChar[i] = "120";
					break;
				case "sizeof":
					nChar[i] = "121";
					break;
				case "static":
					nChar[i] = "122";
					break;
				case "struct":
					nChar[i] = "123";
					break;
				case "string":
					nChar[i] = "124";
					break;
				case "switch":
					nChar[i] = "125";
					break;
				case "typedef":
					nChar[i] = "126";
					break;
				case "unsigned":
					nChar[i] = "127";
					break;
				case "union":
					nChar[i] = "128";
					break;
				case "void":
					nChar[i] = "129";
					break;
				case "while":
					nChar[i] = "130";
					break;
				case "#include":
					nChar[i] = "131";
					break;
				case "#define":
					nChar[i] = "132";
					break;

				}*/
				nChar[i] = "<" + nChar[i] + "#@#" + "$" + ">";
			} else if (FindIntNum.matcher(nChar[i]).matches()) {
				nChar[i] = "<" + "DIGIT" + "#@#" + nChar[i] + ">";
			} else if (FindDoubleNum.matcher(nChar[i]).matches()) {
				nChar[i] = "<" + "Float" + "#@#" + nChar[i] + ">";
			} else if (FindKey2.matcher(nChar[i]).matches()
					&& !FindKey7.matcher(nChar[i]).matches()) {
				/*
				switch (nChar[i]) {
				case "++":
					nChar[i] = "201";
					break;
				case "--":
					nChar[i] = "202";
					break;
				case "%":
					nChar[i] = "203";
					break;
				case "/":
					nChar[i] = "204";
					break;
				case "*":
					nChar[i] = "205";
					break;
				case "+":
					nChar[i] = "206";
					break;
				case "-":
					nChar[i] = "207";
					break;
				}*/
				nChar[i] = "<" + nChar[i] + "#@#" + "$" + ">";
			} else if (FindKey3.matcher(nChar[i]).matches()) {
				nChar[i] = ",";
				nChar[i] = "<" + nChar[i] + "#@#" + "$" + ">";
			} else if (FindKey4.matcher(nChar[i]).matches()) {
				nChar[i] = ";";
				nChar[i] = "<" + nChar[i] + "#@#" + "$" + ">";
			} else if (FindKey5.matcher(nChar[i]).matches()) {
				/*
				switch (nChar[i]) {
				case "<=":
					nChar[i] = "501";
					break;
				case ">=":
					nChar[i] = "502";
					break;
				case "==":
					nChar[i] = "503";
					break;
				case "!=":
					nChar[i] = "504";
					break;
				case "<":
					nChar[i] = "505";
					break;
				case ">":
					nChar[i] = "506";
					break;
				}
				*/
				nChar[i] = "<" + nChar[i] + "#@#" + "$" + ">";
			} else if (FindKey6.matcher(nChar[i]).matches()
					&& !FindKey7.matcher(nChar[i]).matches()
					&& !FindKey9.matcher(nChar[i]).matches()) {
				/*
				switch (nChar[i]) {
				case "!":
					nChar[i] = "601";
					break;
				case "||":
					nChar[i] = "602";
					break;
				case "&&":
					nChar[i] = "603";
					break;
				}*/
				nChar[i] = "<" + nChar[i] + "#@#" + "$" + ">";
			} else if (FindKey7.matcher(nChar[i]).matches()) {
				/*
				switch (nChar[i]) {
				case "=":
					nChar[i] = "701";
					break;
				case "+=":
					nChar[i] = "702";
					break;
				case "-=":
					nChar[i] = "703";
					break;
				case "*=":
					nChar[i] = "704";
					break;
				case "/=":
					nChar[i] = "705";
					break;

				}*/
				nChar[i] = "<" + nChar[i] + "#@#" + "$" + ">";
			} else if (FindKey8.matcher(nChar[i]).matches()) {
				/*
				switch (nChar[i]) {
				case "(":
					nChar[i] = "801";
					break;
				case ")":
					nChar[i] = "802";
					break;
				case "[":
					nChar[i] = "803";
					break;
				case "]":
					nChar[i] = "804";
					break;
				case "{":
					nChar[i] = "805";
					break;
				case "}":
					nChar[i] = "806";
					break;

				}*/
				nChar[i] = "<" + nChar[i] + "#@#" + "$" + ">";
			} else if (FindKey9.matcher(nChar[i]).matches()) {
				/*
				switch (nChar[i]) {
				case "?:":
					nChar[i] = "901";
					break;
				case "~":
					nChar[i] = "902";
					break;
				case "&":
					nChar[i] = "903";
					break;
				}*/
				nChar[i] = "<" + nChar[i] + "#@#" + "$" + ">";
			} else if (FindName.matcher(nChar[i]).matches()) {
				if (MySymbolTable.get(nChar[i]) == null) {
					MySymbolTable.put(nChar[i], 0);
					nkeys[nkeysnum] = nChar[i];
					nkeysnum++;
				}

				/*
				 * int p = -1; a = new SymbolTable(); a.ID = 1; a.name =
				 * nChar[i]; for (j = 0; j < MySymbolTable.size(); j++) { if
				 * (MySymbolTable.get(j).name.equals(a.name)) { p = j; } } if (p
				 * == -1) { MySymbolTable.add(a); p = MySymbolTable.indexOf(a);
				 * }
				 */
				nChar[i] = "<" + "ID" + "#@#" + nChar[i] + ">";

			}
		}
		for (i = 0; i < nCharlen; i++) {
			if (nChar[i] != null && nChar[i].charAt(0) != '<') {
				nChar[i] = "<" + nChar[i] + "#@#" + "error" + ">";
			}
		}

		writeFileByLines(nChar);
		/*
		 * System.out.println(MySymbolTable.size()); for (i = 0; i <
		 * MySymbolTable.size(); i++) {
		 * System.out.println(MySymbolTable.get(nChar[i].hashCode())); }
		 * 
		 * for (i = 0; i < nChar.length; i++) { if (nChar[i] != null) { if
		 * (nChar[i].charAt(nChar[i].length() - 2) != '0') { //
		 * System.out.println(nChar[i]); } } }
		 * 
		 * System.out.println("---符号表---"); for (i = 0; i < nkeysnum; i++) {
		 * System.out.println(nkeys[i]); }
		 */
		String [] Mykeys=new String[nkeysnum];
		for (i=0;i<nkeysnum;i++){
			Mykeys[i]=nkeys[i];
		}
		return Mykeys;

	}
}
