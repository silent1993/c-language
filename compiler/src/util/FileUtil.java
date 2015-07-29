package util;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class FileUtil {
	public static List<String> myGrammarStringList = new ArrayList<String>();
	public static List<String> myTokenList = new ArrayList<String>(); 

	/**
	 * 从文件中读取文法
	 */
	public static List<String> getGrammerFromFile() {
		try {
			BufferedReader br = new BufferedReader(new FileReader(
					"myGrammar.txt"));
			String mGrammar = br.readLine();

			while (mGrammar != null) {
				if (mGrammar.equals("\n"))
					continue;
				myGrammarStringList.add(mGrammar);
				mGrammar = br.readLine();
			}
			br.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return myGrammarStringList;
	}
	
	/**
	 * 从文件中读取token
	 * @return token list
	 */
	public static List<String> getTokenFormFile(){
		try {
			BufferedReader br = new BufferedReader(new FileReader(
					"Word.txt"));
			String mToken = br.readLine();

			while (mToken != null) {
				mToken=mToken.substring(1, mToken.length()-1);
				myTokenList.add(mToken);
				mToken = br.readLine();
			}
			br.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return myTokenList;
	}
	
	public static void WriteFile(String lines,String filename) {
		try {
			File file = new File(filename);
			if (!file.exists()) {
				file.createNewFile();
			}
			FileWriter fileWritter = new FileWriter(file.getName(), false);
			BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
			bufferWritter.write(lines + "\r\n");
			bufferWritter.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	
}
