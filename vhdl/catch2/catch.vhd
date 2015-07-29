----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    22:21:57 05/22/2014 
-- Design Name: 
-- Module Name:    catch - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity catch is
	port(
	A: in STD_LOGIC_VECTOR( 9 downto 0);
   DI: in STD_LOGIC_VECTOR (3 downto 0);
	DO: out STD_LOGIC_VECTOR (3 downto 0);
	CS : IN  std_logic;
   WE : IN  std_logic);
	
end catch;

architecture Behavioral of catch is

	type BIAO is array (15 downto 0) of STD_LOGIC_VECTOR (2 downto 0);
		signal FLAG: BIAO;
	type CA is array (15 downto 0) of STD_LOGIC_VECTOR (31 downto 0);
		signal CAT:CA;
	type mem is array (63 downto 0) of STD_LOGIC_VECTOR(63 downto 0);
	signal  sram : mem;
begin
C1: process (A,DI,CS,WE)
	variable i:integer :=0;
	variable blo:integer ;
	variable temp :integer ;
	--variable tempb :integer ;
	--variable tempc :integer ;
	--variable tempd :integer ;
	variable inblo:integer ;
	variable row: integer ;
	variable col:integer  ;
	
	begin
		temp:=1;
		row:=0;
		blo:=0;
		inblo:=0;
		col:=0;
		l1:for i in 3 to 6 loop
			if A(i)='1' then
				blo:=blo+temp;
			end if;
			temp:=temp*2;
		end loop l1;
		temp:=1;
		l2:for i in 0 to 2 loop
			if A(i)='1' then
				inblo:=inblo+temp;
			end if;
			temp:=temp*2;
		end loop l2;
		temp:=1;
		l3:for i in 3 to 8 loop
			if A(i)='1' then
				row:=row+temp;
			end if;
			temp:=temp*2;
		end loop l3;
		--tempd:=1;
		col:=inblo;
		
	if CS='0'  then
	--read
		if we='1' then				
			if FLAG(blo)(2)=A(9) and FLAG(blo)(1)=A(8) and FLAG(blo)(0)=A(7) then
				DO(3)<=CAT(blo)(inblo+8*3);
				DO(2)<=CAT(blo)(inblo+8*2);
				DO(1)<=CAT(blo)(inblo+8);
				DO(0)<=CAT(blo)(inblo);				
			else
				FLAG(blo)(2)<=A(9) ;
				FLAG(blo)(1)<=A(8) ;
				FLAG(blo)(0)<=A(7) ;
				if A(9)='1' then 
					DO(3)<=sram(row)(col+8 +16*3);
					DO(2)<=sram(row)(col+8+16*2);
					DO(1)<=sram(row)(col+8+16);
					DO(0)<=sram(row)(col+8 );
				elsif A(9)='0' then
					DO(3)<=sram(row)(col +16*3);
					DO(2)<=sram(row)(col +16*2);
					DO(1)<=sram(row)(col+16);
					DO(0)<=sram(row)(col);					
				end if;			
			l5: for i in 7 downto 0 loop
				if A(9)='1' then 
					
					CAT(blo)(i+8*3)<=sram(row)(i+8 +16*3);
					CAT(blo)(i+8*2)<=sram(row)(i+8 +16*2);
					CAT(blo)(i+8)<=sram(row)(i+8 +16);
					CAT(blo)(i)<=sram(row)(i+8 );
				elsif A(9)='0' then	
					CAT(blo)(i+8*3)<=sram(row)(i +16*3);	
					CAT(blo)(i+8*2)<=sram(row)(i +16*2);	
					CAT(blo)(i+8)<=sram(row)(i +16);	
					CAT(blo)(i)<=sram(row)(i );
				end if;
			end loop l5;
		end if;
		--DIO<="ZZZZ";
	--write
	elsif we='0' then
		if FLAG(blo)(2)=A(9) and FLAG(blo)(1)=A(8) and FLAG(blo)(0)=A(7) then
			CAT(blo)(inblo+8*3)<=DI(3);
			CAT(blo)(inblo+8*2)<=DI(2);
			CAT(blo)(inblo+8)<=DI(1);
			CAT(blo)(inblo)<=DI(0);
			if A(9)='1' then 
				sram(row)(col+8+16*3)<=DI(3);
				sram(row)(col+8+16*2)<=DI(2);
				sram(row)(col+8+16*1)<=DI(1);
				sram(row)(col+8)<=DI(0);
			elsif A(9)='0' then		
				sram(row)(col+16*3)<=DI(3);
				sram(row)(col+16*2)<=DI(2);
				sram(row)(col+16*1)<=DI(1);
				sram(row)(col)<=DI(0);
			end if;
		else 
		   FLAG(blo)(2)<=A(9) ;
			FLAG(blo)(1)<=A(8) ;
			FLAG(blo)(0)<=A(7) ;
			--CAT(blo)(inblo+8*3)<=DI(3);
		--	CAT(blo)(inblo+8*2)<=DI(2);
			--CAT(blo)(inblo+8)<=DI(1);
			--CAT(blo)(inblo)<=DI(0);
			if A(9)='1' then 
				sram(row)(col+8+16*3)<=DI(3);
				sram(row)(col+8+16*2)<=DI(2);
				sram(row)(col+8+16*1)<=DI(1);
				sram(row)(col+8)<=DI(0);
			elsif A(9)='0' then		
				sram(row)(col+16*3)<=DI(3);
				sram(row)(col+16*2)<=DI(2);
				sram(row)(col+16*1)<=DI(1);
				sram(row)(col)<=DI(0);
				end if;
		l6: for i in 7 downto 0 loop
				if A(9)='1' then 			
					CAT(blo)(i+8*3)<=sram(row)(i+8 +16*3);
					CAT(blo)(i+8*2)<=sram(row)(i+8 +16*2);
					CAT(blo)(i+8)<=sram(row)(i+8 +16);
					CAT(blo)(i)<=sram(row)(i+8 );
			elsif A(9)='0' then	
					CAT(blo)(i+8*3)<=sram(row)(i+16*3);	
					CAT(blo)(i+8*2)<=sram(row)(i +16*2);	
					CAT(blo)(i+8)<=sram(row)(i+16);	
					CAT(blo)(i)<=sram(row)(i);
				end if;
			end loop l6;
			end if;
			--DIO<="ZZZZ";
		end if;	
end if;		
end process;

end Behavioral;

