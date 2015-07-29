----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    07:29:42 06/25/2014 
-- Design Name: 
-- Module Name:    move - Behavioral 
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

entity move is
    Port ( A : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           B : out  STD_LOGIC);
end move;

architecture Behavioral of move is
--signal internal: STD_LOGIC_VECTOR(3 downto 0);
SIGNAL s: STD_LOGIC ;

       
   BEGIN 
   PROCESS (CLK) BEGIN
	
     IF CLK'EVENT AND CLK = '1'  THEN 
      B<= s; 	
     END IF;
	 S <=A;
  END PROCESS ;


end Behavioral;

