----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:17:27 05/28/2014 
-- Design Name: 
-- Module Name:    catch_stor - Behavioral 
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

entity catch_stor is
    Port ( mCS : in  STD_LOGIC;
           mWE : in  STD_LOGIC;
           mA : in  STD_LOGIC_VECTOR (9 downto 0);
           mDOU : out  STD_LOGIC_VECTOR (3 downto 0);
           mDI : in  STD_LOGIC_VECTOR (3 downto 0));
end catch_stor;

architecture Behavioral of catch_stor is
	 COMPONENT catch2114
    PORT(
         A : IN  std_logic_vector(9 downto 0);
         CS : IN  std_logic;
         WE : IN  std_logic;
         DO : OUT  std_logic_vector(3 downto 0);
         DI : IN  std_logic_vector(3 downto 0)
        );
		  end component;
    COMPONENT catch
    PORT(
         A : IN  std_logic_vector(9 downto 0);
         DOU : INOUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
     
		
begin
cach: catch port map (mA,MDOU);
stor: catch2114 port map (MA,Mcs,Mwe,mDOU,MDI);

end Behavioral;

