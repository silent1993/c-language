----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:13:40 07/08/2014 
-- Design Name: 
-- Module Name:    number1 - Behavioral 
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

entity number1 is
    Port ( CLK : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           T1 : out  STD_LOGIC;
           T2 : out  STD_LOGIC;
           T3 : out  STD_LOGIC;
           T4 : out  STD_LOGIC);
end number1;

architecture Behavioral of number1 is
begin
process(clk,rst)
variable tem:integer;
begin

	if(rst='1')then
		tem:=0;
		t1<='0';
		t2<='0';
		t3<='0';
		t4<='0';
	elsif(clk'event and clk='1') then
		tem:=tem+1;
		if(tem=1) then
			t1<='1';
			t2<='0';
			t3<='0';
			t4<='0';
		elsif(tem=2) then
			t1<='0';
			t2<='1';
			t3<='0';
			t4<='0';
		elsif(tem=3) then
			t1<='0';
			t2<='0';
			t3<='1';
			t4<='0';
		elsif(tem=4) then
			t1<='0';
			t2<='0';
			t3<='0';
			t4<='1';
			tem:=0;
		else
			tem:=0;
	end if;
	end if;
end process;



end Behavioral;

