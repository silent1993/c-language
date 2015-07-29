----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:20:24 07/08/2014 
-- Design Name: 
-- Module Name:    quzhi - Behavioral 
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
use ieee.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity quzhi is
    Port ( PCupdate : in  STD_LOGIC;
           PCnew : in  STD_LOGIC_VECTOR (15 downto 0);
           CS0 : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           MPC : in  STD_LOGIC_VECTOR (15 downto 0);
           IR : out  STD_LOGIC_VECTOR (15 downto 0);
           PC : out  STD_LOGIC_VECTOR (15 downto 0));
end quzhi;

architecture Behavioral of quzhi is

begin
process(PCupdate,PCnew,CS0,RST,MPC)
 variable TPC:STD_LOGIC_VECTOR (15 downto 0) := (others => '0');
begin
if(PCupdate='1')then
		TPC:=PCnew;
		end if;
		
	if(RST='1')then
	TPC:="0000000000000000";
	elsif(CS0='1')then
		PC<=TPC;
		IR<=MPC;
		end if;
		
	

end process;

end Behavioral;

