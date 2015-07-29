----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:33:05 05/22/2014 
-- Design Name: 
-- Module Name:    catche1 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--use IEEE.STD_LOGIC_ARITH.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity catche1 is
	port( 
	A: in STD_LOGIC_VECTOR ( 9 downto 0);
	CS : in STD_LOGIC;
	WE : in STD_LOGIC;
	DIO: inout STD_LOGIC_VECTOR (3 downto 0));
end catche1;

architecture Behavioral of catche1 is
	type mem is array (63 downto 0) of STD_LOGIC_VECTOR(63 downto 0);
	signal  sram : mem;
begin
C1 : process(DIO,CS,WE)
	variable i: integer :=0;
	variable j: integer :=0;
	variable row: integer ;
	variable col:integer  ;
	variable temp:integer :=1 ;
	begin
		l1:for i in 0 to 63 loop
			l2: for j in 0 to 63 loop
				sram(i)(j)<='0';
			end loop l2;
		end loop l1;
		row:=0;
		col:=0;
		l3:for i in 8 downto 3 loop
			if A(i)='1' then
				row:=row+temp;
			end if;
			temp:=temp*2;
		end loop l3;
		temp:=0;
		l4:for i in 2 downto 0 loop
			if A(i)='1' then
				col:=col+temp;
			end if;
			temp:=temp*2;
		end loop l4;
		if A(9)='1' then
				col:=col+temp;
		end if;
		if cs = '0' then
			--read--
			if we = '1' then 
				DIO(3)<=sram(row)(col+16*3);
				DIO(2)<=sram(row)(col+16*2);
				DIO(1)<=sram(row)(col+16);
				DIO(0)<=sram(row)(col);
			--write
			elsif we='0' then
				sram(row)(col+16*3)<=DIO(3);
				sram(row)(col+16*2)<=DIO(2);
				sram(row)(col+16*1)<=DIO(1);
				sram(row)(col)<=DIO(0);
			end if;
		end if;
	end process;
end Behavioral;

