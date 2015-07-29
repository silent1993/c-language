----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:44:18 03/05/2014 
-- Design Name: 
-- Module Name:    lab01 - Behavioral 
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

entity lab01 is
		Port ( led : out STD_LOGIC_VECTOR(7 downto 0);
				 switch : in STD_LOGIC_VECTOR(7 downto 0));
end lab01;

architecture Behavioral of lab01 is

begin
	led <= switch;


end Behavioral;

