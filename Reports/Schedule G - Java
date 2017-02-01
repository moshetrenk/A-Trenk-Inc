import java.io.*;
import java.util.*;

public class Sch {
	static class Var{
		Var(int s, double d){
			sticks = s;
			dollars = d;
		};
		Integer sticks;
		Double dollars;
	}
	static HashMap<String, Var> map = new HashMap<String, Var>();
	static HashMap<String, ArrayList<String>> brandsByCompany = new HashMap<String, ArrayList<String>>();
	static ArrayList<String> valids = getValidBrands(),
			invalids = getInvalidBrands(),
			lines = readFrom(),
			listOfCompanies = new ArrayList<String>();
	static String line1 = lines.get(0),
			startDate = line1.substring(7, 17),
			endDate = line1.substring(38, 48),
			
			//why does this fail if you replace it's value with the string throughout the methods?
			locComputersName = new File("C:\\Users").list()[5];
	static PrintWriter g, d;
	
	public static void main(String[] args) throws IOException{
		lines.remove(0);
		lines.remove(lines.size() - 1);
		
		mapBrands();
		correctExtraFirstSpaceAndFillMap();
		corrections();
		output();
		g.close();
		d.close();

		/*for (HashMap.Entry<String, ArrayList<String>> entry : brandsByCompany.entrySet()) {
			System.out.println(entry.getKey() + "  " + entry.getValue().toString());
			
		}*/
		
	}
	
	static ArrayList<String> getValidBrands(){
		ArrayList<String> valids = new ArrayList<String>();  
		try {
	    	FileReader fileReader = new FileReader("C:\\Users\\" 
	    			+ new File("C:\\Users").list()[5] 
	    			+ "\\Desktop\\Inputs\\valid.txt");  
	    	
	    	BufferedReader bufferedReader = new BufferedReader(fileReader);
	    	String line; 

	    	while((line = bufferedReader.readLine()) != null){
	            	valids.add(line.toLowerCase());
	        }
		      
	    	fileReader.close();

	    } 
	    catch (Exception ex) {
		      System.err.println(ex );
	    }
		
		return valids;	
	}
	
	static ArrayList<String> getInvalidBrands(){
		ArrayList<String> invalids = new ArrayList<String>();  
		try {
	    	FileReader fileReader = new FileReader("C:\\Users\\" 
	    						+ new File("C:\\Users").list()[5]
	    						+ "\\Desktop\\Inputs\\invalid.txt");  
	    	
	    	BufferedReader bufferedReader = new BufferedReader(fileReader);
	    	String line; 

	    	while((line = bufferedReader.readLine()) != null){
	            	invalids.add(line.toLowerCase());
	        }
		      
	    	fileReader.close();
	    } 
	    catch (Exception ex) {
		      System.err.println(ex );
	    }
		return invalids;
	}
	
	public static ArrayList<String> readFrom() {
		ArrayList<String> list = new ArrayList<String>();
		
	    try {
	    	FileReader fileReader = new FileReader("C:\\Users\\" 
	    						+ new File("C:\\Users").list()[5] 
	    						+ "\\Desktop\\Inputs\\sch.txt");  
	    	
	    	BufferedReader bufferedReader = new BufferedReader(fileReader);
	    	String line; 
	    	int i = 0;
	    	while((line = bufferedReader.readLine()) != null){
	            if((i == 0 || i > 9) && (line.length() > 10)){
	            	line = line.substring(6, line.length());
	            	if(line.charAt(0) == ' ')
	            		line = line.substring(1, line.length());
	            	list.add(line.toLowerCase());
	            }
	            i++;
	        }
		      
	    	fileReader.close();

	    } 
	    catch (Exception ex) {
		      System.err.println(ex );
	    }
	    
	    return list; 
	}
	
	static void correctExtraFirstSpaceAndFillMap(){
		for(String a: lines){
			int e = 0;
			for( ; e < a.length(); e++){
				if(a.charAt(e) == ' ')
					break;
			}
			
			String name = a.substring(0, e);

			if (map.containsKey(name)){
				Var var = new Var(map.get(name).sticks + getSticks(a), map.get(name).dollars + getDollars(a));
				map.remove(name);
				map.put(name, var);
			}
			else{
				map.put(name, new Var(getSticks(a), getDollars(a)));
			}
		}
	}
	
	static double getDollars(String string){
		for(int i = string.length() - 1; i > 0; i--){
			if (string.charAt(i) == ' ')
				return Double.valueOf(string.substring(i, string.length()));
		}
		
		return -Double.MAX_VALUE;
	}
	
	static int getSticks(String string){
		for(int i = string.length() - 1, locationOfSpace = -1, hits = 0; i > 0; i--){
			if (string.charAt(i) == ' '){
				if (hits == 0){
					locationOfSpace = i;
					hits++;
				}
				else{
					return Integer.valueOf(string.substring(i + 1, locationOfSpace));
				}
			}
		}
		
		return -Integer.MAX_VALUE;
	}
			
	static void corrections(){
		for(String a : invalids){
			if(map.containsKey(a))
				map.remove(a);
		}
	}
	
	static void output() throws IOException{
		g = new PrintWriter("C:\\Users\\" + new File("C:\\Users").list()[5] + "\\Desktop\\Inputs\\G.csv");
		d = new PrintWriter("C:\\Users\\" + new File("C:\\Users").list()[5] + "\\Desktop\\Inputs\\dollars.csv");
		
		g.println("Start Date: " + startDate + " End Date: " + endDate + "\n");

		for (HashMap.Entry<String, ArrayList<String>> hit : brandsByCompany.entrySet()) {
			System.out.println("key: [value]" + hit.getKey() + "  " + hit.getValue().toString());
			g.println(hit.getKey());
			
			for (HashMap.Entry<String, Var> entry : map.entrySet()) {
				if(valids.contains(entry.getKey()) && !invalids.contains(entry.getKey())){
					//String currentBrand = entry.getKey();
					
					//obviously do for every brand here
					ArrayList<String> k = brandsByCompany.get(hit.getKey());
					
					
					
					System.out.println("k-list to string: " + k.toString());
					
					if(k.contains(entry.getKey().toLowerCase())){
						String e, cur = entry.getKey();

						if (cur.equals("pall"))
							e = "Pall Mall";
						else if (cur.equals("555:00:00"))
							e = "555";
						else if (cur.equals("american") || cur.equals("amer"))
							e = "American Spirit";
						else if (cur.equals("marl"))
							e = "Marlboro";
						else if (cur.equals("vir"))
							e = "Virginia Slim";
						else if(cur.equals("b"))
							e = "Benson & Hedges";
						else if (cur.equals("l"))
							e = "L & M";
						else if (cur.equals("parl"))
							e = "Parliament";
						else
							e = entry.getKey();
								
						String b = Character.toUpperCase(e.charAt(0)) + e.substring(1);
						
						g.println(b + ":  ,," + entry.getValue().sticks * 200);	
						d.println(b + ": ,,Dollars = " + entry.getValue().dollars); 
					}
				} 
				else{
					failed(entry.getKey());
				}
			}
			g.println("");
		}
	}
	
	static void mapBrands(){
		File file = new File("C:\\Users\\" + new File("C:\\Users").list()[5] + "\\Desktop\\Inputs\\Brands");
		
		String[] files = file.list();
		
		for(int i = 0; i < files.length; i++){
			listOfCompanies.add(files[i].toLowerCase());
			ArrayList<String> list = openGenericFileToGetListOfBrands(file + "\\" + files[i].toLowerCase());
			Collections.sort(list);
			brandsByCompany.put(files[i].substring(0, files[i].length() - 4), list);
		}
	}
	
	//only called by mapBrands
	static ArrayList<String> openGenericFileToGetListOfBrands(String fileName){
		ArrayList<String> locBrands = new ArrayList<String>();
		
	    try {
	    	FileReader fileReader = new FileReader(fileName);  
	    	
	    	BufferedReader bufferedReader = new BufferedReader(fileReader);
	    	String line; 
	    	
	    	while((line = bufferedReader.readLine()) != null){
	            locBrands.add(line.toLowerCase());
	        }
		      
	    	fileReader.close();
	    } 
	    catch (Exception ex) {
		      System.err.println(ex );
	    }
	    
	    return locBrands;
	}
	
	static ArrayList<String> getCompanies(){
		ArrayList<String> list = new ArrayList<String>();  
		try {
	    	File fileReader = new File("C:\\Users\\" 
	    			+ new File("C:\\Users").list()[5] 
	    			+ "\\Desktop\\Inputs\\Brands");  
	    	
	    	String[] names = fileReader.list();
	    	for(int i = 0; i < names.length; i++){
	    		list.add(names[i].substring(0, names[i].length() - 4).toLowerCase());
	    	}
	    } 
	    catch (Exception ex) {
		      System.err.println(ex );
	    }
		
		return list;	
	}
	
	static void failed(String str) throws IOException{
		PrintWriter p = new PrintWriter("C:\\Users\\" + new File("C:\\Users").list()[5] + "\\Desktop\\Inputs\\SCHEDULE G FAILED.txt");
		
		p.println(str + " cannot be added to the file, it is not listed among valid brands");
		p.close();
	}
}
