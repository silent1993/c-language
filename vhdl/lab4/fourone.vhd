----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:46:41 07/01/2014 
-- Design Name: 
-- Module Name:    fourone - Behavioral 
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

entity fourone is
    Port ( k0 : in  STD_LOGIC_vector(7 downto 0);
           k1 : in  STD_LOGIC_vector(7 downto 0);
           k2 : in  STD_LOGIC_vector(7 downto 0);
           k3 : in  STD_LOGIC_vector(7 downto 0);
           k4 : in  STD_LOGIC_vector(7 downto 0);
           A : out  STD_LOGIC_vector(7 downto 0);
           B : out  STD_LOGIC_vector(7 downto 0);
           s0 : out  STD_LOGIC_vector(7 downto 0);
           s1 : out  STD_LOGIC_vector(7 downto 0);
           s2 : out  STD_LOGIC_vector(7 downto 0);
           s3 : out  STD_LOGIC_vector(7 downto 0);
           s4 : out  STD_LOGIC_vector(7 downto 0);
           s5 : out  STD_LOGIC_vector(7 downto 0));
end fourone;

architecture Behavioral of fourone is
begin

	s0<=k0;
	s1<=k1;
	s2<=k2;
	s3<=k0;
	s4<=k1;
	s5<=k2;
	A<=k4;
	B<=k3;

end Behavioral;

