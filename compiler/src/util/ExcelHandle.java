package util;

import jxl.*;
import jxl.write.*;

import java.io.*;

public class ExcelHandle {

	public static void writeExcel(OutputStream os, String[] Data,
			String[] title1, String[] title2) {
		try {
			int row = 0;
			int line = 0;
			WritableWorkbook wwb = Workbook.createWorkbook(os);
			WritableSheet ws = wwb.createSheet("Sheet 1", 0);
				
			Label label;
			for(row=0;row<title2.length;row++){
				label = new Label(row+1, 0,title2[row] );
				ws.addCell(label);
			}
			for(line=0;line<title1.length;line++){
				label = new Label(0,line+1,title1[line] );
				ws.addCell(label);
			}
			for(line=0;line<Data.length;line++)
			{
				String tmp[]=Data[line].split("###");
				for(row=0;row<tmp.length;row++){
					label = new Label(row+1,line+1,tmp[row] );
					ws.addCell(label);
				}
			}
			
			

			wwb.write();
			wwb.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void ToExcel(String filename, String[] Data, String[] title1,
			String[] title2) {

		try {
			File fileWrite = new File(filename);
			fileWrite.createNewFile();
			OutputStream os = new FileOutputStream(fileWrite);
			ExcelHandle.writeExcel(os, Data, title1, title2);
			//System.out.println("OK");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}