----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    22:00:43 07/01/2014 
-- Design Name: 
-- Module Name:    store_v - Behavioral 
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

entity store_v is
    Port ( s1 : out  STD_LOGIC_VECTOR (7 downto 0);
           s0 : out  STD_LOGIC_VECTOR (7 downto 0);
			  ad:out STD_LOGIC_VECTOR (15 downto 0);
			  data:inout STD_LOGIC_VECTOR (15 downto 0);
			  cs:out STD_LOGIC;
			  wr:out STD_LOGIC;
			  rd:out STD_LOGIC;
			  bh:out STD_LOGIC;
			  bl:out STD_LOGIC;
           k1 : in  STD_LOGIC_VECTOR (7 downto 0);
           k0 : in  STD_LOGIC_VECTOR (7 downto 0);
           k2 : in  STD_LOGIC_VECTOR (7 downto 0);
           k3 : in  STD_LOGIC_VECTOR (7 downto 0);
           k4 : in  STD_LOGIC_VECTOR (7 downto 0));
end store_v;

architecture Behavioral of store_v is

begin

process(k1,k0,k2,k3,k4)
begin
	if(K4(7)='1')then
		cs<='1';
		wr<='1';
		bh<='1';
		bl<='1';
		rd<='1';
	elsif(k4(7)='0')then
		cs<=k4(1);
	   rd<=k4(0);
		bh<=k4(2);
		bl<=k4(3);
		wr<=k4(4);
		ad(15 downto 8)<=k3;
		ad(7 downto 0)<=k2;
		case k4(4 downto 0) is
			when "10000"=>
				s1<=data(15 downto 8);
				s0<=data(7 downto 0);
				data<="ZZZZZZZZZZZZZZZZ";
			when "00001"=>
				s1<=k1;
				s0<=k0;
				data(15 downto 8)<=k1;
				data(7 downto 0)<=k0;
			when "01001"=>
				s1<=k1;
				data(15 downto 8)<=k1;
			when "11000"=>
				s1<=data(15 downto 8);
				data<="ZZZZZZZZZZZZZZZZ";
			when "00101"=>
				s0<=k0;
				data(7 downto 0)<=k0;
			when "10100"=>
				s0<=data(7 downto 0);
				data<="ZZZZZZZZZZZZZZZZ";
			when others=>NULL;
			end case;
	end if;
end process;
end Behavioral;

