----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:02:30 06/27/2014 
-- Design Name: 
-- Module Name:    ss - Behavioral 
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

entity ss is
    Port ( DI : in  STD_LOGIC;
           DO : out  STD_LOGIC;
           CLK : in  STD_LOGIC);
end ss;

architecture Behavioral of ss is
component move 
Port ( A : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           B : out  STD_LOGIC);
end component;
signal internal: STD_LOGIC_VECTOR(3 downto 0);
begin
internal(3)<=DI;
SH: FOR I in 3 downto 1 GENERATE
	MAPP:component move port map(
	internal(i),CLK,internal(i-1));
end generate;

MAPPL:component move port map(
internal(0),CLK,DO);


end Behavioral;

