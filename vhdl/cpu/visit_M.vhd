----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:35:22 07/08/2014 
-- Design Name: 
-- Module Name:    visit_M - Behavioral 
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

entity visit_M is
    Port (  CS2 : in  STD_LOGIC;
           datain : in  STD_LOGIC_VECTOR (7 downto 0);--in:LDA,OUT 
			  dataout:out STD_LOGIC_VECTOR (7 downto 0);--out:STA,IN
           ALUOUT : in  STD_LOGIC_VECTOR (7 downto 0);
           OP : in  STD_LOGIC_VECTOR (4 downto 0);
           Rtemp : out  STD_LOGIC_VECTOR (7 downto 0);
           IODB : inout  STD_LOGIC_VECTOR (7 downto 0);
			   nPREQ : out  STD_LOGIC;
           nPRD : out  STD_LOGIC;
           nPWR : out  STD_LOGIC);
end visit_M;

architecture Behavioral of visit_M is
signal a:STD_LOGIC_VECTOR (7 downto 0);
begin
process(OP,CS2,ALUOUT,datain,IODB)
begin
	if(CS2='1') then
			case  OP is 
			when "10001"=>
			dataout<=ALUOUT;
			
			when "10011"=>
			Rtemp<=datain;
			
			when "11000"=>
			Rtemp<=IODB;
			IODB<="ZZZZZZZZ";
			nPWR<='1';
			nPREQ<='0';
			nPRD<='0';
			when "11010"=>
			IODB<=ALUOUT;
			nPWR<='0';
			nPREQ<='0';
			nPRD<='1';
			when others=>NULL;
			end case;
end if;
end process;
end Behavioral;

