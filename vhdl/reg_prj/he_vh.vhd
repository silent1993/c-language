----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:32:45 05/19/2014 
-- Design Name: 
-- Module Name:    he_vh - Behavioral 
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

entity he_vh is
    Port ( cs : in  STD_LOGIC;
           wr : in  STD_LOGIC;
           rd : in  STD_LOGIC;
           data_i : in  STD_LOGIC_VECTOR (3 downto 0);
           data_o : out  STD_LOGIC_VECTOR (3 downto 0));
end he_vh;

architecture Behavioral of he_vh is
	signal temp: std_logic_vector (3 downto 0);
begin
	C1: process (wr,rd,cs)
		begin
		if cs ='1' and wr = '1' then
			temp <= data_i;
		else if cs ='1' and rd = '1' then
			data_o <= temp;
		else 
			temp <= temp;
		end if;
		end if;
	end process;


end Behavioral;

